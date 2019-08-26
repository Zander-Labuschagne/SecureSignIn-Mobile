# Secure Sign In Mobile v3
This is a mobile application I have created in an attempt to improve my online account security, it is the latest mobile version (*v3*) of my Secure Sign In project and replaces the Android version (_v2_). The older(and now discontinued) pure Android version can be found at https://gitlab.com/Zander-Labuschagne/SecureSignIn-Android-v2. The user provides a password with an accompanying key that is unique to the website(or account) requiring the password, the application then provides a lengthy and complicated password to be used instead.

#### Compatibility notes:
  - Android 4.1 or later is required to use this application. Please send me an e-mail if this is not the case.
  - *This application was so far only tested on a Sony Xperia X Compact running Android 8.0.0. and iPhone 8 running iOS 12.4*
  - *Although this application runs on iOS, it is still in the process of being developed for iOS and is not functioning properly on iOS yet.*

#### Benifits:
  - Remember one password for all sites, but all sites have different passwords.
  - Don't know the actual password which is entered in the password box on the website.
  - Provides a very strong, long and complex password.
  - No passwords are stored in file or database.
  - Easy to use.

This is my first C++(Qt/QML) application for Android and iOS devices I have created. Feel free to criticize or comment on my code and practices.
There are desktop applications available as well, however some are not always up to date and I have left some of them discontinued/incomplete. I work on these projects in my free time only so expect irregular updates from me.

Desktop version: https://gitlab.com/Zander-Labuschagne/SecureSignIn-v4b

Sailfish OS version: *In progress*
  
The logo and name on the application comes from an iWorks template, it is not a registered company name or logo, I just added it to make it look impressive.

E-Mail: <zander.labuschagne@protonmail.ch>

Copyright (C) 2019 Zander Labuschagne. This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License version 2 as published by the Free Software Foundation.

#### Installation:
Copy the *SecureSignIn_arm64_v8a.apk* Android binary file found inside the *bin* folder to you Android smartphone/tablet device using a USB cable.

#### How to use application (also see screens below):
  1. Enter a password you will remember in the password box, preferably a strong and complicated password because this will influence the complexity of the resulting password.
  2. Enter a key, such as google, facebook or whatever.
  3. Click on Encrypt Password and the rest is self explanatory. The password is cleared from memory after 8 seconds when copying the password.

#### Android Screens
<img src="https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/front_end.png" alt="Main view. Enter password and key in text fields." width="300" align="middle"/>
<!--![alt text](https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/front_end.png =720x "Main view. Enter password and key in text fields.")-->
<img src="https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/front_end_compact.png" alt="Main view showing example. In this case the `compact password` option is enabled to shorten the password if necessary." width="300" align="middle"/>
<!--![alt text](https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/front_end_compact.png "Main view showing example. In this case the `compact password` option is enabled to shorten the password if necessary.")-->
<img src="https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/output_view.png" alt="Output view showing output of example. Copy the password to memory for pasting, or reveal the password for type over." width="300" align="middle"/>
<!--![alt text](https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/output_view.png "Output view showing output of example. Copy the password to memory for pasting, or reveal the password for type over.")-->

#### iOS 1st Build
<img src="https://gitlab.com/Zander-Labuschagne/SecureSignIn-Mobile/raw/master/screens/ios_1st_build.png" alt="Main screen in iOS.." width="300" align="middle"/>
