
if __name__ == '__main__':
    for t in range(int(input())):
        input()
        exp = input().split(" ")

        if  not exp[0].isdigit(): 
            exp[0] = int(exp[4]) - int(exp[2])
        elif not exp[2].isdigit(): 
            exp[2] =  int(exp[4]) - int(exp[0])
        else: 
            exp[4] = int(exp[0]) + int(exp[2])
        print(f"{exp[0]} + {exp[2]} = {exp[4]}")
