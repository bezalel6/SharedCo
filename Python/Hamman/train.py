import speech_recognition as sr
import webbrowser as wb
import pickle
import sys

while bool(1):
    r1 = sr.Recognizer()
    r2 = sr.Recognizer()
    r3 = sr.Recognizer()
    
    
    with sr.Microphone() as source:
        print('speak now')
        audio = r3.listen(source)
    
    lst = []
    with open('list.txt', 'r') as filehandle:
        for line in filehandle:
            # remove linebreak which is the last character of the string
            currentStr = line[:-1]
    
            # add item to the list
            lst.append(currentStr)
            
    print(*lst) 
    found = r2.recognize_google(audio,language='he')
    isExist = 0
    for word in lst:
        if found == word:
            isExist = 1
    if not(bool(isExist)):
        add = input('add word: '+found+' ')
        if 'stop' in add:
            sys.exit()
        if 'y' in add:
                lst.append(found)
                with open('list.txt', 'w') as filehandle:
                    for listitem in lst:
                        filehandle.write('%s\n' % listitem)
    
    
    
