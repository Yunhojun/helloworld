import random

def switch(x, row, col, myList):
    if(x == 'create'):
        return create_list(row,col,myList)
    elif(x=='init'):
        return init_list(row,col,myList)
    elif(x=='print'):
        return print_list(myList)

def create_list(row, col, myList=[]):
    #Create 2D list by using list expression and for loop
    myList = [row][col]
    for i in range(row):
        for j in range(col):
            myList[i][j]=0
    return myList

def init_list(row, col,myList):
    #prev_list is list stored previous random number in myList
    prev_list=[]
    for c in range(col):
        for r in range(row):
            number=random.randint(1,col*row)
            #The while loop will continue to run until there is no duplication
            while(1):
                #if a random number is in prev_list then we should generate random number again
                if number in prev_list:
                    number=random.randint(1, col*row)
                #if a random number is unique then we push number to prev_list and exit the while loop
                else:
                    prev_list.append(number)
                    break
            myList[r][c]=number
    return myList

def print_list(myList):
    for col in myList:
        for elem in col:
            print("%d\t"%elem, end='')
        print()
        return myList

if __name__ == '__main__':
    #Enter row, column size through user keybroad
    row=int(input("Row : "))
    col=int(input("Column : "))
    #Call functions
    myList = []
    while(1):
        x=input("keword: ")
        myList = switch(x,row,col,myList)