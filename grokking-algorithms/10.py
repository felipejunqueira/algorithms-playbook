voted = {}
#the same of voted = dict()

def verifica_eleitor(nome):
    if voted.get(nome): #if TRUE
        print ("mande embora!")
    else: #if NONE
        voted[nome] = True
        print ("let's vote!")


print("first time tom:", voted.get("tom"))
verifica_eleitor("tom")
print("second time tom:", voted.get("tom"))
verifica_eleitor("tom")

