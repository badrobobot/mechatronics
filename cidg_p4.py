while True:
  while True:
    deg = input("Write a sexagecimal degree: ")
    try:
      deg = int(deg)
      break
    except ValueError:
      print("Invalid charecter. Try again")
      pass 
    
  print(deg)
  pass
      
 
