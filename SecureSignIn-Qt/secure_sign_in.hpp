#ifndef SECURE_SIGN_IN_HPP
#define SECURE_SIGN_IN_HPP

/*
 * Class containing encryption function(s) for the Secure Sign In applications
 *
 * Author:
 *	Zander Labuschagne <zander.labuschagne@protonmail.ch>
*/

class SecureSignIn
{
public:
	SecureSignIn();
	char *encrypt(const char *, const char *, const unsigned short);
	unsigned short get_length(const char *);
};

#endif // SECURE_SIGN_IN_HPP
