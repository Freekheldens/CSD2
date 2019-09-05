import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/plingel.wav")

play_times = input("How many times would you like to hear the sample? ")

if str.isdigit(play_times):
    i = 0
    while i < int(play_times):
        play_obj = wave_obj.play()
        play_obj.wait_done()
        i += 1
    else:
        print("All done!")
else:
    print("Wrong input!")
