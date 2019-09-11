import simpleaudio as sa
import time

wave_obj = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/RS01.wav")

play_times = int(input("How many times would you like to hear the sample? "))

list_rythm_values = []

for times in range(play_times):
    rythm_values = (input("Please enter a number that represents the lenght of a note: "))
    list_rythm_values.append(rythm_values)

bpm = input("Please enter a BPM: ")
bpm = (60000/float(bpm))

for rythms in list_rythm_values:
    rythms = float(rythms)
    play_obj = wave_obj.play()
    print(str(rythms*bpm) + " ms")
    time.sleep((rythms*bpm)/1000)
