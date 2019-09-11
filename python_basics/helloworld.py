username = input("Please enter your name: ") #input je naam
age = int (input("Please enter your age: ")) #input je leeftijd

if age < 18:                                 # kijkt of je input leeftijd kleiner is als 18
  print("Sorry you are to young :(")         # dit wordt uitgevoerd als de leeftijd kleiner is dan 18
else:
  print("Hello " + username + "!")           # dit wordt uitgevoerd als leeftijd gelijk is of groter is dan 18
