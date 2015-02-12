#!/bin/sh
#Script Made to Backup all Your modified contact from iCloud to Mac Contacts
#By: Isb (igorsca(aT)gmail.com)
#If your paranoia is like mine, puts this on your MacOSX crontab's 
#like this --> 5 9,15,21 * * * /Users/YourHome/Downloads/linux/scripts/licloud.sh
#This make a copy of all icloud contacts changes to your local machine.
#its iCloud best local backup

cloud=$HOME/Library/Application\ Support/AddressBook/Sources/73913E37-57B4-4A14-BC49-CFF65F8DF2BB/
local=$HOME/Library/Application\ Support/AddressBook/
cloudimg=$HOME/Library/Application\ Support/AddressBook/Sources/73913E37-57B4-4A14-BC49-CFF65F8DF2BB/Images/
cloudmetadata=$HOME/Library/Application\ Support/AddressBook/Sources/73913E37-57B4-4A14-BC49-CFF65F8DF2BB/Metadata
localimg=$HOME/Library/Application\ Support/AddressBook/Images/
localmetadata=$HOME/Library/Application\ Support/AddressBook/Metadata/
addb='abcddb'
person='abcdp'
group='abcdg'
time='240 minute ago'

killall Contacts
find "$cloudimg" \! -type d -newerct "$time" -exec cp -f {} "$localimg" \; 
(cd "$cloudmetadata";cp -f `find ./ -type f|fgrep -e "$person" -e "$group"` "$localmetadata")
(cd "$cloud";cp -f `find ./ -type f|fgrep -e "$addb"` "$local")
exit 0
