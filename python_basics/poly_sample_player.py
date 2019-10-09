import simpleaudio as sa
import time

#path to samples
kick_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/bd01.wav")
clap_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/cp01.wav")
hihat_sample = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/Sound Files/hh01.wav")

#lists that are used later
durations_list = [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5]
time_stamps16th = []
time_stamps_msec = []
kick_list = [1, 0, 1, 0, 1, 0, 1, 0]
clap_list = [0, 0, 1, 0, 0, 0, 1, 0]
hihat_list = [1, 1, 1, 1, 1, 1, 1, 1]

#slects which samples to play
def sample_poly():
    if kick_list[x-1] == 1:
        kick_sample.play()
        print("kick")
    if clap_list[x-1] == 1:
        clap_sample.play()
        print("snare")
    if hihat_list[x-1] == 1:
        hihat_sample.play()
        print("hihat")
    print("-------------------")

#BPM input from user, only excepts a valid input
while True:
    try:
        BPM = float(input("Standard BPM is 120, you can now change it or just hit enter: ") or 120)
    except ValueError:
        print("Please enter a number")
        continue
    else:
        break

#function to convert duration_list to 16th timestamps
def durations_to_timestamps16th(note_durations):
    time_stamps16th.append(0)
    step = 0
    for duration in note_durations:
        time_stamps16th.append(duration * 4 + step)
        step = step + duration * 4
    del time_stamps16th[-1]

#function to convert 16th timestamps to msec timestamp calculated with BPM input
def stamps_to_time (time_stamps_list, BPM):
    BPM = float(BPM)
    for timestamp in time_stamps_list:
        time_stamps_msec.append((timestamp * (60 / BPM) / 4))

#calling the functions from above
durations_to_timestamps16th(durations_list)
stamps_to_time(time_stamps16th, BPM)
print(time_stamps_msec)
#times to loop
loop_count = 4
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
        if(currentTime - startTime >= time_stamps_msec[x-1]):
            print(x)
            sample_poly()
            if x >= 1:
                x = (x + 1) % len(time_stamps_msec)
                print(currentTime - startTime)
            else:
                #if x = 0
                loop_play = False
        else:
            time.sleep(0.001)
    #wait until the measure is finished
    time.sleep(((60/BPM)*4) - time_stamps_msec[-1])
