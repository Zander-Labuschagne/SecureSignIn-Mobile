#include <iostream>

unsigned short get_length(char* ptr_array)
{
        unsigned short ix;
        for (ix = 0; *(ptr_array + ix) != '\0'; ++ix);

        return ++ix;  // Include the last null character to signal end, otherwise weird things happen
}

//TODO: moet dalk nie return nie, doen pass by reference
char* encrypt(const char *password_in, const char *key, unsigned short limit)
{
        char *password = (char*)malloc(256);
        for (int z = 0; z < 256; ++z)
                *(password + z) = '\0';
        unsigned short key_index = 0;
        unsigned short i = 0;
        char *spec_chars = (char*)malloc(256);
        for (int z = 0; z < 256; ++z)
                *(spec_chars + z) = '\0';
        unsigned short ii = 0;
        unsigned short spec_char_count = 0;
        unsigned short password_length = 0;

        for (char t = *password_in; t != '\0'; t = *(password_in + ++password_length)) {
                if (t >= 65 && t <= 90) { // Encrypting uppercase characters
                        short temp = t - 65 + (*(key + key_index) - 65);
                        if (temp < 0)
                                temp += 26;
                        if (temp <= 0)
                                temp += 26;

                        *(password + i++) = (char)(65 + (temp % 26));

                        if (*(key + ++key_index) == '\0')
                                key_index = 0;
                } else if (t >= 97 && t <= 122) { // Encrypting lowercase characters
                        short temp = t - 97 + (*(key + key_index) - 97);
                        if (temp < 0)
                                temp += 26;
                        if (temp < 0)
                                temp += 26;

                        *(password + i++) = (char)(97 + (temp % 26));

                        if (*(key + ++key_index) == '\0')
                                key_index = 0;
                } else { // Encrypting special characters and positions of these special characters respectively
                        *(spec_chars + ii++) = (char)(password_length + 65);
                        *(spec_chars + ii++) = t;
                }
        }

        char *password_proc = (char*)malloc(256);
        i = 0;

        *(password_proc + i++) = (char)(spec_char_count == 0 ? 65 : (--spec_char_count + 65)); // Encrypting the number of special characters

        for (char t = *spec_chars; t != '\0'; i++, t = *(spec_chars + i - 1)) //Merging special characters and positions of special characters into cipher password
                *(password_proc + i) = t;
        ii = i;

        for (char t = *password; t != '\0'; i++, t = *(password + i - ii)) // Adding the encrypted password to the encrypted special characters and positions in the cipher password
                *(password_proc + i) = t;

        free(password);
        free(spec_chars);

        unsigned short length = get_length(password_proc); // Count the number of characters to eliminate a bunch of null characters at the end

        char *password_out = (char*)malloc(length);
        for (unsigned short xi = 0; xi < length; ++xi) // Move password from big memory to just the right amount of memory
                *(password_out + xi) = *(password_proc + xi);

        free(password_proc);

        char *evens = (char*)malloc(256);//TODO: Pasop!
        char *odds = (char*)malloc(256);
        unsigned short xii = 0, xiii = 0;
        for (unsigned short iii = 0; iii < length - 1; ++iii) // - 1 to exclude the last null character
                if ((unsigned short)(*(password_out + iii) % 2 == 0))
                        *(evens + xii++) = *(password_out + iii);
                else
                        *(odds + xiii++) = *(password_out + iii);

        char *odds_reversed = (char*)malloc(xiii);
        for (unsigned short xvi = 0, xvii = xiii; xvii > 0; --xvii, ++xvi) // Reverse odds, like stack
                *(odds_reversed + xvi) = *(odds + xvii - 1);

        free(odds);

        unsigned short iv = 0;
        unsigned short xiv = 0;
        unsigned short xv = 0;
        while (xii > 0 || xiii > 0) { //Obfuscation
                if (xiii > 0) {
                        *(password_out + iv++) = *(odds_reversed + xiv++);
                        --xiii;
                }
                if (xii > 0) {
                        *(password_out + iv++) = *(evens + xv++);
                        --xii;
                }
        }

        free(evens);
        free(odds_reversed);

        for (unsigned short v = 0; v < length - 1; ++v) // Encrypt special characters further. Remember not to encrypt the last null character(- 1)
                if ((unsigned short)(*(password_out + v)) <= 47)
                        *(password_out + v) += 10;
                else if ((unsigned short)(*(password_out + v)) > 47 && (unsigned short)(*(password_out + v)) < 64)
                        *(password_out + v) -= 5;
                else if ((unsigned short)(*(password_out + v)) > 90 && (unsigned short)(*(password_out)) <= 96) {
                        if (length % 2 == 0)
                                *(password_out + v) += 2;
                        else
                                *(password_out + v) -= 2;
                }

        for (unsigned short vi = 0; vi < length; ++vi) //Replacing unloved characters
                if ((unsigned short)(*(password_out + vi)) == 34)
                        *(password_out + vi) = 123;
                else if((unsigned short)(*(password_out + vi)) == 38)
                        *(password_out + vi) = 124;
                else if ((unsigned short)(*(password_out + vi)) == 60)
                        *(password_out + vi) = 125;
                else if ((unsigned short)(*(password_out + vi)) == 62)
                        *(password_out + vi) = 126;

        if (limit < 32) { // Password length limitations
                char *password_limited = (char*)malloc(length);
                for (unsigned short vii = 0; vii < length && vii < limit; ++vii)
                        *(password_limited + vii) = *(password_out + vii);
                unsigned short length_limited = get_length(password_limited); // Count the number of characters to eliminate a bunch of null characters at the end

                char *password_out_limited = (char*)malloc(length_limited);
                for (unsigned short xi = 0; xi < length_limited; ++xi) // Move password from big memory to just the right amount of memory
                        *(password_out_limited + xi) = *(password_limited + xi);

                free(password_limited);
                free(password_out);

                return password_out_limited;
        }

        return password_out;
}

int main()
{
        std::string p = "Knight|Hawke 256-512";
        std::string k = "Google";
        char *c;// = encrypt(p.c_str(), k.c_str(), 32);

        //std::cout << "Die nuwe password is: " << c << std::endl;

        for (int i = 0; i < 10; ++i) {
                c = encrypt(p.c_str(), k.c_str(), 32);
                std::cout << "Die nuwe password is: " << c << std::endl;
        }

        free(c);
        //delete c;

        return 0;
}
