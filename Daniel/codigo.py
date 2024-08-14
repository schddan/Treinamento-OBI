#Código da tarefa "Código de compressão" da fase 2 da prova de programação nível 2 da OBI 2023

N = int(input())
cadeia = input()

count = 1
values = [1]
chars = []
for index in range(0, N):
    if index == 0:
        chars.append(cadeia[index])
        continue
    elif cadeia[index] == cadeia[index-1]:
        count += 1
        values[-1] = count
    else:
        count = 1
        values.append(count)
        chars.append(cadeia[index])

saida = ''
for index in range(0, len(chars)):
    saida += str(values[index]) + ' ' + chars[index] + ' '

saida = saida.rstrip()

print(saida)