import random
from midiutil import MIDIFile
import simpleaudio as sa
import time

print("")
print("Welcome!")

print("")
print("--------------------------------------------------------------------------------")
print("")

#input from user for time signature
while True:
    try:
        time_sig1 = int(input("Please enter a number of beats per measure: -----------------> ") or 5)
    except ValueError:
        print("")
        print("Please enter a number!")
        print("")
        continue
    else:
        if time_sig1 == 0:
            print("")
            print("Please enter a number!")
            print("")
            continue
        break

print                 ("                                                               -")

#input from user for time signature
while True:
    try:
        time_sig2 = int(input("Please enter a 2, 4 or 8 (this represents the note duration):  ") or 4)
    except ValueError:
        print("")
        print("Please enter a 2, 4 or 8!")
        print("")
        continue
    else:
        if time_sig2 != 2 and time_sig2 != 4 and time_sig2 != 8:
            print("")
            print("Please enter a 2, 4 or 8!")
            print("")
            continue
        break

print("")
print("--------------------------------------------------------------------------------")
print("")

print("Your chosen time signature is: " + str(time_sig1) + "/" + str(time_sig2) + "!")

print("")
print("--------------------------------------------------------------------------------")
print("")

#input from user for BPM
while True:
    try:
        BPM = float(input("Pleae enter a BPM (standard is 120): ") or 120)
    except ValueError:
        print("")
        print("Please enter a number!")
        print("")
        continue
    else:
        if BPM == 0:
            print("")
            print("Please enter a number!")
            print("")
            continue
        break

print("")
print("--------------------------------------------------------------------------------")
print("")

#input from user for amount of loops
while True:
    try:
        loop_count = int(input("How many times would you like to play the loop (standard is 2): ") or 2)
    except ValueError:
        print("")
        print("Please enter a number!")
        print("")
        continue
    else:
        if loop_count == 0:
            print("")
            print("Please enter a number!")
            print("")
            continue
        break

print("")
print("--------------------------------------------------------------------------------")
print("")

#input from user for choice of drumkit
while True:
    try:
        drumkit_choice = int(input("Please enter your prefered drumkit, 909 or 808 (standard is 909): ") or 909)
    except ValueError:
        print("")
        print("Please enter 909 or 808!")
        print("")
        continue
    else:
        if drumkit_choice != 909 and drumkit_choice != 808:
            print("")
            print("Please enter 909 or 808!")
            print("")
            continue
        break

print("")
print("--------------------------------------------------------------------------------")
print("")

#converts time_sig2 to "quarter notes"
if time_sig2 == 8:
    time_sig2 = 2
elif time_sig2 == 2:
    time_sig2 = 8
elif time_sig2 == 1:
    time_sig2 = 16

#calculates how many 16th steps there are in given time signature
sixtheenth_amount = time_sig1 * time_sig2

#makes list of 16th time indications in msec
i = 0
msec_list = [0]
while i < sixtheenth_amount:
    msec_list.append((15/BPM)+msec_list[-1])
    i += 1
msec_list.pop(-1)

#empty lists to fill
kick_list = []
clap_list = []
hihat_list = []

#calculates kick placement
i = 0
while i < sixtheenth_amount:
    if i == 0 or i == (sixtheenth_amount/2):
        kick_list.append(1)
    elif i == (sixtheenth_amount/4) and (random.randint(0, 100)) >= 50:
        kick_list.append(1)
    elif i == (sixtheenth_amount-(sixtheenth_amount/4)) and (random.randint(0, 100)) >= 50:
        kick_list.append(1)
    elif random.randint(0, 100) >= 90:
        kick_list.append(1)
    else:
        kick_list.append(0)
    i += 1

#calculates clap placement
i = 0
while i < sixtheenth_amount:
    if i == 0 or i == (sixtheenth_amount/2):
        clap_list.append(0)
    elif i == (sixtheenth_amount/4):
        clap_list.append(0)
    elif i == (sixtheenth_amount-(sixtheenth_amount/4)):
        clap_list.append(0)
    elif random.randint(0, 100) >= 75:
        clap_list.append(1)
    else:
        clap_list.append(0)
    i += 1

#calculates hihat placement
i = 0
while i < sixtheenth_amount:
    if random.randint(0, 100) >= 75:
        hihat_list.append(1)
    else:
        hihat_list.append(0)
    i += 1

#MIDI file write
degrees  = kick_list # MIDI note number
track    = 0
channel  = 9
timer    = 0   # In beats
tempo    = BPM  # In BPM
volume   = 100 # 0-127, as per the MIDI standard

MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track automatically created)
MyMIDI.addTempo(track, timer, tempo)

for volume in degrees:
    MyMIDI.addNote(track, channel, 36, timer, 0.25, volume*100)
    timer = timer + 0.25

degrees = clap_list
timer = 0
for volume in degrees:
    MyMIDI.addNote(track, channel, 38, timer, 0.25, volume*100)
    timer = timer + 0.25

degrees = hihat_list
timer = 0
for volume in degrees:
    MyMIDI.addNote(track, channel, 42, timer, 0.25, volume*100)
    timer = timer + 0.25

with open("midi_irr_beat.mid", "wb") as output_file:
    MyMIDI.writeFile(output_file)

#print lists
print("Kicks:  " + str(kick_list))
print("Claps:  " + str(clap_list))
print("Hihats: " + str(hihat_list))
print("")

#sample loader
if drumkit_choice == 909:
    kick_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/bd01.wav")
    clap_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/cp01.wav")
    hihat_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/hh01.wav")
elif drumkit_choice == 808:
        kick_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/bd808.wav")
        clap_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/cb808.wav")
        hihat_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/ch808.wav")

#slects which samples to play
def sample_poly():
    if kick_list[x-1] == 1:
        kick_sample.play()
    if clap_list[x-1] == 1:
        clap_sample.play()
    if hihat_list[x-1] == 1:
        hihat_sample.play()

#loop and play system
i = 0
while i < loop_count:
    #setting start time
    startTime = time.time()
    i += 1
    print("---------")
    print("loop: " + str(i))
    #x for modulo and list index
    x = 1
    loop_play = True
    #loop for playing sample
    while loop_play == True:
        currentTime = time.time()
        #checking if it is time to play a sample
        if(currentTime - startTime >= msec_list[x-1]):
            #print(x)
            sample_poly()
            if x >= 1:
                x = (x + 1) % len(msec_list)
                #print(currentTime - startTime)
            else:
                #if x = 0
                loop_play = False
        else:
            time.sleep(0.001)
    #wait until the measure is finished
    time.sleep(15/BPM)
time.sleep(0.25)

print("---------")
print("")
print("All done! Midi file is saved!")
print("")
print("")
