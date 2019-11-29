import  re
import sys
if __name__ == '__main__':
    with open('./dlnote.txt','rb') as responseFile:
        response = str(responseFile.read())
        findlist = re.findall(r'<input(.*"wpUnicodeCheck")/>',response)
        if len(findlist) > 0:
            print(findlist[0])


    pass