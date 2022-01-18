# Problem Set 2, hangman.py
# Name:  Ding
# Collaborators:
# Time spent:

# Hangman Game
import random       #用于随机性抽取单词
import string  

WORDLIST_FILENAME = "words.txt"   #文件名

def load_words():   #加载txt文件中的单词，并说明单词数量，并返回[words]
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')   #打开文件，操作方式为只读
    # line: string
    line = inFile.readline()                #读取文件
    # wordlist: list of strings
    wordlist = line.split()                #将单词以空格为分界，形成单词列表
    print("  ", len(wordlist), "words loaded.")   #打印单词数量
    return wordlist            #返回的是所有单词的列表 --> [words]

def choose_word(wordlist):   #返回列表中的一个单词
    """
    wordlist (list): list of words (strings)
    
    Returns a word from wordlist at random
    """
    #随机地从文本的单词中挑一个
    return random.choice(wordlist)


wordlist = load_words()    #wordlist为包含所有单词的列表

#用于判断单词中出现的字母是否都被猜过
#如果secret_word中所有组成单词的字母均在letters_guessed中，则返回true
#因此在这里可以直接用循环加in的方法完成判断
def is_word_guessed(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing; assumes all letters are
      lowercase
    letters_guessed: list (of letters), which letters have been guessed so far;
      assumes that all letters are lowercase
    returns: boolean, True if all the letters of secret_word are in letters_guessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    for each1 in secret_word:   #each1为每一个在secret_word中的字母
        if each1 not in letters_guessed:  #如果有字母不在已经猜过的字母内，返回False
            return False
    return True  #说明所有的字母都在已经猜过的单词内，故返回True


#将secret_word中的已经猜测的字母显示出来，未猜的字母显示未'_ '  ！！注意，这里是下划线加空格
#思路：如果secret_word中的某个字母已经出现，则显示，否则用'_ '代替
#      类似上一题思路，用for循环加in的方式判断即可
def get_guessed_word(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string, comprised of letters, underscores (_), and spaces that represents
      which letters in secret_word have been guessed so far.
    '''
    #通过已经猜过的字母确定出现在猜词的样子  例如这样标识“app_ _”
    result=''                  #创建一个新的空字符串，用于存储结果
    for each in secret_word:   #each是secret_word中出现的所有字母
        if each in letters_guessed: 
            result+=each       #如果each已经被猜出，则将其加到result结尾        
        else:                                   
            result+='_ '       #如果each没有被猜出，则在result结尾加上'_ '
    return result              #返回result结果即可
    


#这个函数主要是把26个字母中仍旧有可能出现(去掉已经猜过的)的按顺序显示出来
#可以调用 string.ascii_lowercase函数，这个函数将返回 26个小写字母的排序后的序列
#因此只需要把猜过的字母从中去掉即可
def get_available_letters(letters_guessed):
    '''
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string (of letters), comprised of letters that represents which letters have not
      yet been guessed.
    '''
    #将26个字母(除去已经猜过的字母)顺序输出来
    start=string.ascii_lowercase   #将start赋值为26个小写字母按顺序排序的序列
    result=''                      #用result存储结果
    for each in start:             #each表示每一个小写字母
        if each in letters_guessed:  #如果该小写字母之前已经猜过，则continue
            continue
        else:                      #如果该小写字母之前没有猜过，则将其加入result的序列
            result+=each
    return result                 #返回result即可
    
#用vowels存储元音字母    
vowels=['a','e','i','o']  #题目说明元音为 a e i o

#返回一个单词中不同的字母数量,用于计分时的辅助函数
def unique_letters(words): 
    help_string=''                
    for each in words:              #each为每一个在单词中出现的字母
        if each not in help_string: #如果each不在help_string里，则表示是新的一个字母，将其加入help_string
            help_string+=each  
        else:                       #如果each在help_string里，则表示是一个出现过的单词，忽略
            continue
    return len(help_string)        #返回help_string的长度即可

#游戏主体
def hangman(secret_word):
    '''
    secret_word: string, the secret word to guess.
    
    Starts up an interactive game of Hangman.
    
    * At the start of the game, let the user know how many 
      letters the secret_word contains and how many guesses s/he starts with.
      
    * The user should start with 6 guesses

    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    
    * Ask the user to supply one guess per round. Remember to make
      sure that the user puts in a letter!
    
    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the 
      partially guessed word so far.
    
    Follows the other limitations detailed in the problem write-up.
    '''
    #游戏的开头：
    print("Welcome to the game Hangman!")
    #告诉用户单词的长度
    print("I am thinking of a word that is %d letters long."%(len(secret_word)))
    print('You have 3 warnings left.')
    all_lowercase=string.ascii_lowercase  #用于存储所有的小写字母，用作判断字符是否有效的辅助
    print("-------------")
    available_letters= get_available_letters('')  
    #初始化acailable_letter，用available_letters存储还可以用于猜测的字母
    guess_chance=6   #guess_chance表示 猜测次数剩余，初始为6  
    warnings_chance=3   #warnings_chance表示 警告次数剩余，初始为3
    guessed=[]        #用guessed[]存储已经猜过的字母
    success=False    #用作标记，记录是否赢得游戏
    while guess_chance>0 : #如果猜测机会没有用完则可以继续游戏，如果赢得话会break出循环
        print("You have %d guesses left."%(guess_chance))  #每次告诉用户还有多少机会剩余
        print("Available letters: %s"%(available_letters),end="") #告诉用户当前有效的猜测
        my_guess=input("Please guess a letter:") #提示用户输入自己的猜测
        my_guess=my_guess.lower() #将用户输入进行小写化      
        if my_guess not in all_lowercase or len(my_guess)!=1: #如果用户输入的不是单个字母，则warning
            warnings_chance-=1   #警告机会-1
            if warnings_chance<0:  #如果警告机会用完则扣除猜测机会
                guess_chance-=1    
                print("Oops! That is not a valid letter. You have no warnings left.")
                print("so you lose one guess: %s"%(get_guessed_word(secret_word,guessed)))
                print('------------')
            else:  #如果警告机会还有剩余则仅扣除警告机会即可
                print("Oops! That is not a valid letter. You have %d warnings left:%s"%(warnings_chance,get_guessed_word(secret_word,guessed)))
                print('------------')
                continue  #结束本次循环
                
        if my_guess not in available_letters:  #输入单词合法但是不在应该输入的字母序列中，说明该字母已经猜过
            warnings_chance-=1  #警告用户，并减少一次警告次数
            if warnings_chance<0:  #如果警告机会用完则减少一次猜测机会
                guess_chance-=1
                print("Oops! You've already guessed that letter.You have no warnings left.") 
                print('so you lose one guess: %s'%(get_guessed_word(secret_word,guessed)))
                print('------------')
                continue  #结束本次循环
            else:  #警告机会还没用完，则仅扣除一次猜测机会
                print("Oops! You've already guessed that letter. You have %d warnings left: %s"%(warnings_chance,get_guessed_word(secret_word,guessed)))
                print('------------')
                continue  #结束本次循环
                
        else:    #这说明输入的单词是符合要求且存在于用户应该猜测的词堆中
            if my_guess not in secret_word:  #猜的字母不在单词里，说明猜错
                if guess_chance==1:   #如果猜测机会只剩一次，则-1，避免出现-2后到-1的情况
                    guess_chance=0
                elif my_guess in vowels:  #如果是元音减2次机会
                    guess_chance-=2    
                else:
                    guess_chance-=1     #如果是辅音减1次机会
                print("Oops! That letter is not in my word:",(get_guessed_word(secret_word,guessed)))
                guessed.append(my_guess)  #将mu_guess加入到guessed列表中
                available_letters= get_available_letters(guessed)  #更新available_letters
                print('------------')   
                
            else:        #说明猜测的单词存在于secret_guess中
                guessed.append(my_guess)  #更新guessed
                available_letters=get_available_letters(guessed)   #更新available_letters
                print("Good guess: ",get_guessed_word(secret_word,guessed))#显示出 单词形态
                print("------------")
                if  is_word_guessed(secret_word, guessed):#如果猜出所有单词
                    success=True
                    break
    if success==True:  #说明猜词成功:显示相应输出并计算得分
        print("Congratulations, you won!")
        print('Your total score for this game is: ',(guess_chance*unique_letters(secret_word)))
    else:         #说明机会用完游戏失败，显示相应的输出，并告诉玩家单词是什么
        print('Sorry, you ran out of guesses. The word was',secret_word)

# When you've completed your hangman function, scroll down to the bottom
# of the file and uncomment the first two lines to test
#(hint: you might want to pick your own
# secret_word while you're doing your own testing)


# -----------------------------------


#显示出my_word与other_word是否可以匹配，也就是说other_word是否是答案的一种情况
#长度不匹配直接pass
#长度匹配但某个字母不匹配直接pass
#如果上述都匹配但‘_‘代表的字母已经出现过则pass
#否则可以返回True
def match_with_gaps(my_word, other_word):
    '''
    my_word: string with _ characters, current guess of secret word
    other_word: string, regular English word
    returns: boolean, True if all the actual letters of my_word match the 
        corresponding letters of other_word, or the letter is the special symbol
        _ , and my_word and other_word are of the same length;
        False otherwise: 
    '''
    my_word = ''.join(my_word.split())  # 删掉my_word空格
    if len(my_word)!=len(other_word):   #长度不匹配  pass
        return False
    else:            
        i=0
        result=''
        for each in my_word:       
            if each!='_':
                result+=each       #用result存储不包括'_'的部分
                
        while i<len(my_word):      
            if my_word[i]!='_' and my_word[i]!=other_word[i]: #如果某一个位置不匹配
                return False
            if my_word[i]=='_' and other_word[i] in result:  #出现'ap_ le'与'apple'的情况则不匹配
                return False
            i+=1
    return True
         
         
             



def show_possible_matches(my_word):
    #显示出所有有可能是答案的单词
    '''
    my_word: string with _ characters, current guess of secret word
    returns: nothing, but should print out every word in wordlist that matches my_word
             Keep in mind that in hangman when a letter is guessed, all the positions
             at which that letter occurs in the secret word are revealed.
             Therefore, the hidden letter(_ ) cannot be one of the letters in the word
             that has already been revealed.

    '''
    flag=False     #标记是否有匹配单词
    for each in wordlist:
        if match_with_gaps(my_word,each):
            flag=True            #如果有匹配单词则打印在屏幕上并标记flag=true
            print(each,' ',end='')
    if flag==False:              #如果没有任何匹配单词则在屏幕打印no matches found
        print("No matches found")
    else:
        print("")
        
    



def hangman_with_hints(secret_word):
    '''
    secret_word: string, the secret word to guess.
    
    Starts up an interactive game of Hangman.
    
    * At the start of the game, let the user know how many 
      letters the secret_word contains and how many guesses s/he starts with.
      
    * The user should start with 6 guesses
    
    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    
    * Ask the user to supply one guess per round. Make sure to check that the user guesses a letter
      
    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the 
      partially guessed word so far.
      
    * If the guess is the symbol *, print out all words in wordlist that
      matches the current guessed word. 
    
    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
        #游戏的开头：
    print("Welcome to the game Hangman!")
    #告诉用户单词的长度
    print("I am thinking of a word that is %d letters long."%(len(secret_word)))
    #print('You have 3 warnings left.')
    print("-------------")
    #print("You have 6 guesses left.") #告诉用户他开始的时候有6次猜测机会
    available_letters= get_available_letters('')  
    #初始化acailable_letter，用available_letters存储还可以用于猜测的字母
    #print("Available letters: %s"%(available_letters),end="")
    #打印 available_letters
    guess_chance=6   #guess_chance表示 猜测次数剩余，初始为6  
    warnings_chance=3   #warnings_chance表示 警告次数剩余，初始为3
    guessed=[]  #用guessed[]存储已经猜过的字母
    success=False  #标记是否成功
    while guess_chance>0 : #如果猜测机会没有用完则可以继续游戏
        print("You have %d guesses left."%(guess_chance))
        print("Available letters: %s"%(available_letters),end="")
        my_guess=input("Please guess a letter:") #提示用户输入自己的猜测
        my_guess=my_guess.lower() #将用户输入进行小写化
        all_lowercase=string.ascii_lowercase
     #   if str.isalpha(my_guess) and str.islower(my_guess):      
        if my_guess=='*':
            print('Possible word matches are:')
            show_possible_matches(get_guessed_word(secret_word,guessed))
            continue
        elif my_guess not in all_lowercase or len(my_guess)!=1:
            warnings_chance-=1
            if warnings_chance<0:
                guess_chance-=1
                print("Oops! That is not a valid letter. You have no warnings left.")
                print("so you lose one guess: %s"%(get_guessed_word(secret_word,guessed)))
                print('------------')
            else:
                print("Oops! That is not a valid letter. You have %d warnings left:%s"%(warnings_chance,get_guessed_word(secret_word,guessed)))
                print('------------')
                continue  #结束本次循环
        if my_guess not in available_letters:  #输入单词合法但是不在应该输入的字母序列中，说明该字母已经猜过
            warnings_chance-=1  #警告用户，并减少一次警告次数
            if warnings_chance<0:  #如果警告机会用完则减少一次猜测机会
                guess_chance-=1
                print("Oops! You've already guessed that letter.You have no warnings left.") 
                print('so you lose one guess: %s'%(get_guessed_word(secret_word,guessed)))
                print('------------')
                continue  #结束本次循环
            else:  #警告机会还没用完
                print("Oops! You've already guessed that letter. You have %d warnings left: %s"%(warnings_chance,get_guessed_word(secret_word,guessed)))
                print('------------')
                continue  #结束本次循环
        else:    #这说明输入的单词是符合要求且存在于用户应该猜测的词堆中
            if my_guess not in secret_word:  #猜的字母不在单词里，说明猜错
                if guess_chance==1:   #如果猜测机会只剩一次，则-1，避免出现-2后到-1的情况
                    guess_chance=0
                elif my_guess in vowels:  #如果是元音减2次机会
                    guess_chance-=2    
                else:
                    guess_chance-=1     #如果是辅音减1次机会
                print("Oops! That letter is not in my word:",(get_guessed_word(secret_word,guessed)))
                guessed.append(my_guess)  #将mu_guess加入到guessed列表中
                available_letters= get_available_letters(guessed)  #更新available_letters
                print('------------')   
            else:        #说明猜测的单词存在于secret_guess中
                guessed.append(my_guess)  #更新guessed
                available_letters=get_available_letters(guessed)   #更新available_letters
                print("Good guess: ",get_guessed_word(secret_word,guessed))#显示出 单词形态
                print("------------")
                if  is_word_guessed(secret_word, guessed):#猜出所有单词
                    success=True
                    break
    if success==True:#说明猜词成功:
        print("Congratulations, you won!")
        print('Your total score for this game is: ',(guess_chance*unique_letters(secret_word)))
    else:
        print('Sorry, you ran out of guesses. The word was',secret_word)



# When you've completed your hangman_with_hint function, comment the two similar
# lines above that were used to run the hangman function, and then uncomment
# these two lines and run this file to test!
# Hint: You might want to pick your own secret_word while you're testing.


if __name__ == "__main__":
    # pass

    # To test part 2, comment out the pass line above and
    # uncomment the following two lines.
    
    secret_word = choose_word(wordlist)
    hangman(secret_word)

###############
    
    # To test part 3 re-comment out the above lines and 
    # uncomment the following two lines. 
    
    #secret_word = choose_word(wordlist)
    #hangman_with_hints(secret_word)

