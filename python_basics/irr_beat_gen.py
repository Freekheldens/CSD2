from pyfiglet import Figlet
import random
from midiutil import MIDIFile
import simpleaudio as sa
import time

print("\n------------------------------------------------------------------------------\n")

#welcome font
name_sign = Figlet(font='slant')
print(name_sign.renderText('Irr Beat Gen V.1'))
print("\n------------------------------------------------------------------------------\n")

#input from user for time signature, does not accept invalid input
while True:
    try:
        time_sig = input("Please enter a time signature like so: number/number\nThe second number can only be a 2, 4 or 8\n\n") or "7/8"
        time_sig_list = time_sig.split("/")
        time_sig1 = int(time_sig_list[0])
        time_sig2 = int(time_sig_list[1])
    except ValueError:
        print("\nYou can only enter (whole) numbers!\n")
        continue
    except IndexError:
        print("\nYou need to enter two numbers!\n")
        continue
    else:
        if time_sig1 == 0 or time_sig1 < 0:
            print("\nPlease enter a number higher than 0!\n")
            continue
        elif time_sig1 > 16:
            print("\nPlease enter a number lower than 16!\n")
            continue
        else:
            if time_sig2 != 2 and time_sig2 != 4 and time_sig2 != 8:
                print("\nPlease enter a 2, 4 or 8 as second number!\n")
                continue
        break

print("\n------------------------------------------------------------------------------\n")

print("Your chosen time signature is: " + str(time_sig1) + "/" + str(time_sig2) + "!")

print("\n------------------------------------------------------------------------------\n")

#input from user for BPM, does not accept invalid input
while True:
    try:
        BPM = float(input("Please enter a BPM (standard is 120): \n\n") or 120)
    except ValueError:
        print("\nPlease enter a number!\n")
        continue
    else:
        if BPM == 0 or  BPM < 0:
            print("\nPlease enter a number higher than 0!\n")
            continue
        elif BPM > 250:
            print("\nPlease enter a number lower than 250!\n")
            continue
        elif BPM < 30:
            print("\nPlease enter a number higher than 30!\n")
            continue
        break

print("\n------------------------------------------------------------------------------\n")

#input from user for amount of loops, does not accept invalid input
while True:
    try:
        loop_count = int(input("How many times would you like to play the loop (standard is 2): \n\n") or 2)
    except ValueError:
        print("\nPlease enter a number!\n")
        continue
    else:
        if loop_count == 0 or loop_count < 0:
            print("\nPlease enter a number higher than 0!\n")
            continue
        elif loop_count > 16:
            print("\nPlease enter a number lower than 16!\n")
            continue
        break

print("\n------------------------------------------------------------------------------\n")

#input from user for choice of drumkit, does not accept invalid input
while True:
    drumkit_choice = (input("Please enter your preferred drumkit, 909 or 808 (standard is 909): \n\n") or ("909"))
    if drumkit_choice != ("909") and drumkit_choice != ("808"):
        print("\nPlease enter 909 or 808!\n")
        continue
    else:
        break

print("\n------------------------------------------------------------------------------\n")

#converts time_sig2 to "quarter notes" so calculation of 16th amount can be done
if time_sig2 == 8:
    time_sig2 = 2
elif time_sig2 == 2:
    time_sig2 = 8

#calculates how many 16th steps there are in given time signature
sixtheenth_amount = time_sig1 * time_sig2

#makes a list of 16th time indications, this is for the play loop system
i = 0
msec_list = [0]
while i < sixtheenth_amount:
    msec_list.append((15/BPM)+msec_list[-1])
    i += 1
msec_list.pop(-1)

#empty lists to fill with ones or zeros
kick_list = []
clap_list = []
hihat_list = []

#calculates kick placement, done with probality
i = 0
while i < sixtheenth_amount:
    #always a kick on the first and in the "middle" of a bar
    if i == 0 or i == (sixtheenth_amount/2):
        kick_list.append(1)
    #50% chance for a kick on 1/4 of the bar (rounded in case of time sig: "i/8")
    elif i == round(sixtheenth_amount/4) and (random.randint(0, 100)) >= 50:
        kick_list.append(1)
    #50% chance for kick on 3/4 of the bar (rounded in case of time sig: "i/8")
    elif i == round(sixtheenth_amount-(sixtheenth_amount/4)) and (random.randint(0, 100)) >= 50:
        kick_list.append(1)
    #5% chance for a kick anywhere else
    elif random.randint(0, 100) >= 95:
        kick_list.append(1)
    else:
        kick_list.append(0)
    i += 1

#calculates clap placement, done with probality
i = 0
while i < sixtheenth_amount:
    #no clap on the first and in the "middle" of a bar
    if i == 0 or i == (sixtheenth_amount/2):
        clap_list.append(0)
    #no clap on 1/4 of the bar (rounded in case of time sig: "i/8")
    elif i == round(sixtheenth_amount/4):
        clap_list.append(0)
    #no clap on 3/4 of the bar (rounded in case of time sig: "i/8")
    elif i == round(sixtheenth_amount-(sixtheenth_amount/4)):
        clap_list.append(0)
    #90% chance for clap on 1/8 of the bar (rounded in case of time sig: "i/8")
    elif i == round(sixtheenth_amount/8) and (random.randint(0, 100)) >= 10:
        clap_list.append(1)
    #90% chance for clap on 5/8 of the bar (rounded in case of time sig: "i/8")
    elif i == round((sixtheenth_amount/2)+(sixtheenth_amount/8)) and (random.randint(0, 100)) >= 10:
        clap_list.append(1)
    #50% chance for clap on 3/8 of the bar (rounded in case of time sig: "i/8")
    elif i == round(sixtheenth_amount-(sixtheenth_amount/8)) and (random.randint(0, 100)) >= 50:
        clap_list.append(1)
    #50% chance for clap on 7/8 of the bar (rounded in case of time sig: "i/8")
    elif i == round((sixtheenth_amount/2)-(sixtheenth_amount/8)) and (random.randint(0, 100)) >= 50:
        clap_list.append(1)
    #5% chance of a clap anywhere else
    elif random.randint(0, 100) >= 95:
        clap_list.append(1)
    else:
        clap_list.append(0)
    i += 1

#calculates hihat placement, done with probality
i = 0
while i < sixtheenth_amount:
    #no hihat on 1/8 of the bar
    if i == round(sixtheenth_amount/8):
        hihat_list.append(0)
    #no hihat on 3/8 of the bar
    elif i == round(sixtheenth_amount-(sixtheenth_amount/8)):
        hihat_list.append(0)
    #no hihat on 5/8 of the bar
    elif i == round((sixtheenth_amount/2)+(sixtheenth_amount/8)):
        hihat_list.append(0)
    #no hihat on 7/8 of the bar
    elif i == round((sixtheenth_amount/2)-(sixtheenth_amount/8)):
        hihat_list.append(0)
    #75% chance of a hihat anywhere else
    elif random.randint(0, 100) >= 25:
        hihat_list.append(1)
    else:
        hihat_list.append(0)
    i += 1

#function to convert list of 1's and 0's to "x" and "-"
def grid_maker (instrumen_list, grid_list):
    i = 0
    while i < len(instrumen_list):
        if instrumen_list[i] == 1:
            grid_list.append("x")
        else:
            grid_list.append("-")
        i += 1
    grid_list.insert(0, "")
    grid_list.append("")

#makes a good looking "grid" from the hihat_list an prints it
hihat_grid = []
grid_maker(hihat_list, hihat_grid)
hihat_grid_string = '|'.join([str(item) for item in hihat_grid])
print("Hihat " + hihat_grid_string)

#makes a good looking "grid" from the clap_list an prints it
clap_grid = []
grid_maker(clap_list, clap_grid)
clap_grid_string = '|'.join([str(item) for item in clap_grid])
print("Clap  " + clap_grid_string)

#makes a good looking "grid" from the kick_list an prints it
kick_grid = []
grid_maker(kick_list, kick_grid)
kick_grid_string = '|'.join([str(item) for item in kick_grid])
print("Kick  " + kick_grid_string)
print("\n")

#loads samples based on the choise from user
if drumkit_choice == ("909"):
    kick_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/bd01.wav")
    clap_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/cp01.wav")
    hihat_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/hh01.wav")
elif drumkit_choice == ("808"):
        kick_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/bd808.wav")
        clap_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/cb808.wav")
        hihat_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/ch808.wav")

#slecets which samples to play, a "1" in the lists means play and "0" means dont play
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
    #x is for modulo and list index
    x = 1
    loop_play = True
    #loop for playing sample
    while loop_play == True:
        currentTime = time.time()
        #checking if it is time to play a sample
        if(currentTime - startTime >= msec_list[x-1]):
            sample_poly()
            if x >= 1:
                #modulo for going through list
                x = (x + 1) % len(msec_list)
            else:
                loop_play = False
        else:
            #wait time to check if it is time to play something again
            time.sleep(0.001)
    #wait until the measure is finished
    time.sleep(15/BPM)

print("\n------------------------------------------------------------------------------\n")

#input from user, user can choose if he/she wants to save Midi file, only accepts valid input
while True:
    midi_save_choice = (input("Would you like to save the beat in a Midi file?\nPlease enter yes or no:\n\n") or ("yes"))
    if midi_save_choice != ("yes") and midi_save_choice != ("no"):
        print("\nPlease enter yes or no!\n")
        continue
    else:
        break

if midi_save_choice == ("yes"):
    print("\n------------------------------------------------------------------------------\n")
    #input from user for Midi file name
    midi_file_name = (input("Please enter a file name:\n\n") or ("midi_irr_beat"))
    #adds .mid to name entered by user
    midi_file_name = str(midi_file_name) + (".mid")

    #MIDI file write
    degrees  = kick_list # MIDI note number
    track    = 0
    channel  = 9
    timer    = 0   # In beats
    tempo    = BPM  # In BPM
    volume   = 100 # 0-127, as per the MIDI standard

    MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track automatically created)
    MyMIDI.addTempo(track, timer, tempo)
    #writes kick's on midi note 36
    for volume in degrees:
        MyMIDI.addNote(track, channel, 36, timer, 0.25, volume*100)
        timer = timer + 0.25
    #writes clap's on midi note 38
    degrees = clap_list
    timer = 0
    for volume in degrees:
        MyMIDI.addNote(track, channel, 38, timer, 0.25, volume*100)
        timer = timer + 0.25
    #writes hihat's on midi note 42
    degrees = hihat_list
    timer = 0
    for volume in degrees:
        MyMIDI.addNote(track, channel, 42, timer, 0.25, volume*100)
        timer = timer + 0.25
    #writes the midi file with chosen name
    with open(midi_file_name, "wb") as output_file:
        MyMIDI.writeFile(output_file)
        print("\n------------------------------------------------------------------------------\n")
        print(str(midi_file_name) + " file is saved!\n\n")
#if user does not want save midi file
else:
    print("\n------------------------------------------------------------------------------\n")
    print("No Midi file saved!\n\n")
    exit()
