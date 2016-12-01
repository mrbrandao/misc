### Linux Builder ###

The linux builder project is a simple bunch of script to keep all your personal system wide configuration in only one place.

Imageine every time you change a /etc/ config file you or a profile changes you have to change again os copy your files again and again across your personal machines just to keep your profile... Thats very punch in a ass...
So i made this tools to keep documented and synced all configuration files and profiles in more simple way...

### How this works ? ###

All began with a simple script called ```distros.sh``` this script is very simple it has the objetive to map the files across you linux flavor to set all the env vars of files you want to keep track on your distro...

All is so fresh so for now it dont has support yet to all distros... but it's very simple to append...

 * Adding config files

To add config files the first thing you have to do is set env vars on ```distros.sh``` to the files you want to change...
Like samples:
    
    HOSTS="hosts" #just set the name of the config file
    PATHHOSTS="/etc/$HOSTS" #set the full path in your distro to this config file
    TMPHOSTS="/tmp/$HOSTS" #set the tmp file for config file during changes
    TMPHOSTSRUN="/tmp/$HOSTS-run" #set tmp config file during applier

 * Adding personal entryies to config files

Now that you already have all env vars setted to your new config file all you need to do is set the changes that you need to track in this file... To do this quest you have to add a simple function key on ```build.sh``` script...
Sample:

```
myhosts() {

myhosts[0]="##This is a commentary in my hosts file"
myhosts[1]="192.168.1.1    gw gateway router"
myhosts[2]="192.168.1.254  web www webserver"

source ./applier.sh myhosts $PATHHOSTS $TMPHOSTS $TMPHOSTSRUN

}
```

Ok... thats all... This is all you have to do by adding new changes on your system...

What this funcion does is, add each line of array myhosts at end of your /etc/hosts file... So it whill add 3 lines in this. Each line must be in sequency of this array....

Keep in mind this is a very beta software so for now the first argument to the ```applier.sh``` shell must be the array name in this case myhosts the other three are the env vars you have seted on ```build.sh``` and it must also follow this **order sequency**

### Running ###

```
$ ./build.sh
```
_If all your config file are placed in your home file it must work without sudo_

```
$ sudo ./build
```
_To set changes on system wile you need to call this shell with superuser cowpoers_

<strong>Enjoy by: isca    :pouting_cat:</strong>