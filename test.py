import os
import sys
import subprocess

toSearch  = sys.argv[1];
searchResults = subprocess.check_output(['sudo', 'apt-cache', 'search',toSearch])

listOfProgs = searchResults.split('\n')


try:
    for oneProg in listOfProgs:
        try:
            progName = oneProg.split(' ')[0]
            print "\n\n\nInstalling Prog -> "+progName +"\n\n\n"
            os.system('sudo apt-get -y install ' + progName)
        except KeyboardInterrupt:
            print "\n\n\nDone"
            sys.exit(1)
except KeyboardInterrupt:
    print "\n\n\nDone"
    sys.exit(1)

print "\n\n\nDone"