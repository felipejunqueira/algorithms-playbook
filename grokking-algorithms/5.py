def sauda(nome):
    print("ola, " + nome + "!")
    sauda2(nome)
    print("preparando pra dizer tchau...")
    tchau()

def sauda2(nome):
    print("como vai, " + nome + "?")

def tchau():
    print ("ok, tchau!")

nome = 'felipe'
sauda('felipe')
