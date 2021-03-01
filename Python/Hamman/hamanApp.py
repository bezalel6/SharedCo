import kivy
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty
import speech_recognition as sr
import webbrowser as wb
import pickle
import time
from threading import Thread
from playsound import playsound
import tkinter as tk
from tkinter import filedialog

class MyGrid(Widget):
    head = ObjectProperty(None)    
    foot = ObjectProperty(None) 
    var = 0
    onColor = [1,0,0,1]
    offColor = [0,1,0,1]
    mp3File ='Sound/horn.mp3'
    def btn(self):
        x = Thread(target=self.test,daemon=True)
        x.start()
        print("Started")

        if(bool(self.var)):
            self.var = 0
        else:
            self.var = 1
            
    def test(self):
        self.head.text = "Not Listening "
        self.foot.text = "Status "
        while(bool(self.var)):
            r1 = sr.Recognizer()
            r2 = sr.Recognizer()
            r3 = sr.Recognizer()
            with sr.Microphone() as source:
                if not(bool(self.var)):
                    self.test()
                self.head.text = 'Listening...'
                audio = r3.listen(source)
            
            lst = []
            with open('list.txt', 'r') as filehandle:
                for line in filehandle:
                    # remove linebreak which is the last character of the string
                    currentStr = line[:-1]
                    # add item to the list
                    lst.append(currentStr)            
            try:
                found = r2.recognize_google(audio,language='he')
                self.head.text = found
                isExist = 0
                for word in lst:
                    if found == word:
                        isExist = 1
                if(bool(isExist)):
                    self.foundHaman()
            except sr.UnknownValueError:
                self.foot.text = "Couldn't recognize"
            except sr.RequestError as e:
                self.foot.text = 'failed'.format(e)
            time.sleep(2)
                    
        time.sleep(1)
        self.test()
        
    
    def setSound(self):
        root  = tk.Tk()
        root.withdraw()
        self.mp3File = filedialog.askopenfilename()
    
    def foundHaman(self):
        self.foot.text = 'haman = shit'
        
        # Play the mp3 file
        playsound(self.mp3File)
        
        
class MyApp(App):
    def build(self):
        return MyGrid()
        


if __name__ == "__main__":
    MyApp().run()
