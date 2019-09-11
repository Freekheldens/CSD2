import simpleaudio as sa                                                                                        #import simpleaudio en zo kun je het oproepen als sa

wave_obj = sa.WaveObject.from_wave_file("/Users/freek/School/Jaar 2/CSD/Git/CSD2/python_basics/plingel.wav")    #path naar bestand en de soundfile krijgt de naam: wave_obj

def play_sound():
    try:                                                                                                        #dit is om te controleren of de input een int is
        play_times = int(input("How many times would you like to hear the sample? "))                           #dit wordt uitgevoerd als de input een int is
        for number in range(play_times):                                                                        #range maakt er een voor for een bruikbaare int van
            play_obj = wave_obj.play()
            play_obj.wait_done()
    except ValueError:                                                                                          #dit wordt uitgevoerd als de inout geen int is
        print("Please enter a number!")
        exit()

play_sound()

print("All done!")
