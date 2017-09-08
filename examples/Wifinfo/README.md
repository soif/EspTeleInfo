Wifinfo
==========================

This is a generic Teleinfo French Meter Measure Wifi Runtime, it can be used on Arduino like device and also such as Spark Core, Particle, ESP8266, Raspberry PI or anywhere you can do Cpp code ...

You can see Teleinformation official french datasheet [there][1]

Since this is really dedicated to French energy measuring system, I will continue in French

###Installation sur un Wemos D1 Mini
<br/>
Copier le contenu de ce dossier (download zip) dans le dossier libraries de votre environnement Arduino Vous devriez avoir maintenant quelque chose comme `your_sketchbook_folder/Wifinfo` et ce dossier doit contentir les fichiers .cpp et .h ainsi que le sous dossier `data`.
<br/>
Pour trouver votre dossier de sketchbook, dans l'environnement IDE, allez dans File>Preferences.
<br/>
allez voir ce [tutorial][2] sur les librairies Arduino si beoin.
<br/>
NB: La librairie [LibTeleinfo][14] est un des pré-requis. Ce référer à son readme pour plus d'information
<br/>
Une fois le projet Arduino importé dans votre environnement, il ne vous reste plus qu'à compiler (CTRL+R) et à uploader le binaire sur votre Wemos

###Changements apportés sur les versions:

* 1.0.2
	* Added Domoticz Management (Data Push) -- BETA
	* Added SPIFFS flash management (Handling both CPP.BIN and SPIFFS.BIN flashing)
	* Added Info logging (File + Serial) in addition of Debug logging (Serial only)
	* Added File Logging rotation (limited to 1, every 1K reached)
	* Added Web view of the File logger
	* Fixed Jeedom html field id mistake
	* Added AP_RETRYCOUNT config to manage retrycount for Wifi to connect (fix for some internet box)
	* Fixed options saving to config
	* Added Delete button on files management web page
	* Added Upload area on files management web page with overrite if file was existing
	* Fixed no teleinfo data table refresh when calling root / page
	* Updated Port / Protocol definition to manage ports like 8080 instead of only 80 or 443
	* Added support for Basic Authentication within HttpPost function (used for Domoticz)
* 1.0.1
* 1.0.0
- Se référer au blog [Wifinfo][5]

Pour les commentaires et le support vous pouvez allez sur le [forum][8] dédié ou dans la [communauté][9] 

##License
Cette oeuvre est mise à disposition selon les termes de la Licence Creative Commons Attribution - Pas d’Utilisation Commerciale - Partage dans les Mêmes Conditions 4.0 International.

Si vous êtes une entreprise et que vous souhaitez participer car vous utilisez cette librairie dans du hardware (box, automate, ...), vous pouvez toujours m'envoyer un exemplaire de votre fabrication, c'est toujours sympa de voir ce qui est fait avec ce code ;-)

##Divers
Vous pouvez aller voir les nouveautés et autres projets sur [blog][7] 

[1]: http://www.erdf.fr/sites/default/files/ERDF-NOI-CPT_02E.pdf
[2]: http://learn.adafruit.com/arduino-tips-tricks-and-techniques/arduino-libraries
[6]: https://hallard.me/category/tinfo/
[7]: https://hallard.me
[8]: https://community.hallard.me/category/7
[9]: https://community.hallard.me
[10]: https://hallard.me/libteleinfo

[3]: https://github.com/hallard/LibTeleinfo/blob/master/Examples/Arduino_Softserial/Arduino_Softserial_Etiquette.ino
[4]: https://github.com/hallard/LibTeleinfo/blob/master/Examples/Arduino_Softserial_JSON/Arduino_Softserial_JSON.ino
[5]: https://github.com/hallard/LibTeleinfo/tree/master/examples/Wifinfo/Wifinfo.ino
[11]: https://github.com/hallard/LibTeleinfo/blob/master/Examples/Arduino_Softserial/Arduino_Softserial_Blink.ino
[12]: https://github.com/hallard/LibTeleinfo/blob/master/Examples/Raspberry_JSON/Raspberry_JSON.ino
[13]: https://hallard.me/wifiinfo/
[14]: https://github.com/hallard/LibTeleinfo