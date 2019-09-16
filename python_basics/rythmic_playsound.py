import simpleaudio as sa                                                                                        #import simpleaudio module
import time                                                                                                     #import time module

wave_obj = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/RS01.wav")       #path naar audiofile

list_rythm_values = []                                                                                          #lege lijst waar de nootlengtes in worden gezet

play_times = int(input("How many times would you like to hear the sample? "))

for times in range(play_times):                                                                                 #loop om de lijst te vullen
    rythm_values = (input("Give each playback time its own length, 1 = quarter note 0.5 = 8th note etc."))
    list_rythm_values.append(rythm_values)

bpm = input("Please enter a BPM: ")
if(bpm.isdigit()):
    bpm = (60000/float(bpm))                                                                                    #rekent bpm om naar milliseconde
else:
    print("Please enter a number!")
    exit()

for rythms in list_rythm_values:                                                                                #loop die de sample afspeelt met de delay's
    rythms = float(rythms)
    play_obj = wave_obj.play()
    print(str(rythms*bpm) + " ms")
    time.sleep((rythms*bpm)/1000)
