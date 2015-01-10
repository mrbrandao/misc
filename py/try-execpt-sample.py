#!/usr/local/bin/python
# -*- coding: utf-8 -*- 

#Make hours rate job

pergunta1 = raw_input('Quantas horas você trabalhou? : ')
try:
    entrada1 = int(pergunta1)
    print 'Muito bom... você me falou que foram', entrada1, 'horas'
    pergunta2 = raw_input('Quanto custa sua mao de obra? : ')
    try:
        entrada2 = float(pergunta2)
        print 'Opa... vejo que sua mao de obra custa ',entrada2, 'R$'
        print 'Iniciando calculo de horas....'
        resultado = entrada1 * entrada2
        print 'Voce ira receber o total de:', resultado, 'R$ este mes'
    except:
        print 'Ops... desculpe so consigo receber sua mao de obra em numeros' 
except:
    print 'Ops... so prosso usar numeros inteiros, e', pergunta1, 'nao me parece ser um numero interiro...'
exit()


