import random
import simpleaudio as sa
import time

print("")
print("Welcome!")
print("")
print("--------------------------------------------------------------------------------")
print("")

while True:
    try:
        time_sig1 = int(input("Please enter a number of beats per measure: -----------------> ") or 5)
    except ValueError:
        print("")
        print("Please enter a number!")
        print("")
        continue
    else:
        break

print                 ("                                                               -")

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

while True:
    try:
        BPM = float(input("Standard BPM is 120, you can now change it or just hit enter: ") or 120)
    except ValueError:
        print("")
        print("Please enter a number!")
        print("")
        continue
    else:
        break

print("")
print("--------------------------------------------------------------------------------")
print("")
print("Your chosen BPM is: " + str(BPM))
print("")
print("--------------------------------------------------------------------------------")

print("")
while True:
    try:
        loop_count = int(input("How many times would you like to play the loop (standard is 1): ") or 1)
    except ValueError:
        print("")
        print("Please enter a number!")
        print("")
        continue
    else:
        break

print("")
print("--------------------------------------------------------------------------------")
print("")

if time_sig2 == 8:
    time_sig2 = 2
elif time_sig2 == 2:
    time_sig2 = 8
elif time_sig2 == 1:
    time_sig2 = 16

sixtheenth_amount = time_sig1 * time_sig2

i = 0
msec_list = [0]
while i < sixtheenth_amount:
    msec_list.append((15/BPM)+msec_list[-1])
    i += 1
msec_list.pop(-1)

kick_list = []
clap_list = []
hihat_list = []

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

i = 0
while i < sixtheenth_amount:
    if random.randint(0, 100) >= 75:
        hihat_list.append(1)
    else:
        hihat_list.append(0)
    i += 1

print("Kicks:  " + str(kick_list))
print("Claps:  " + str(clap_list))
print("Hihats: " + str(hihat_list))
print("")

#path to samples
kick_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/bd01.wav")
clap_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/cp01.wav")
hihat_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/hh01.wav")

#slects which samples to play
def sample_poly():
    if kick_list[x-1] == 1:
        kick_sample.play()
    if clap_list[x-1] == 1:
        clap_sample.play()
    if hihat_list[x-1] == 1:
        hihat_sample.play()

#loop system
i = 0
while i < loop_count:
    #setting start time
    startTime = time.time()
    i += 1
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
time.sleep(0.5)
