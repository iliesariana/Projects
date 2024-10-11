class GamePlay:
    def __init__(self,repo):
        self.__repo=repo

    def swap1(self, sentence, word1, letter1, word2, letter2):
        sentence.History.append(sentence.Display)

        words = sentence.Display.split(" ")

        # Convert the relevant words to lists
        list1 = list(words[word1])
        list2 = list(words[word2])

        # Swap the characters
        ch1=list1[letter1]
        ch2=list2[letter2]
        list1[letter1]=ch2
        list2[letter2]=ch1

        # Convert lists back to strings
        words[word1] = "".join(list1)
        words[word2] = "".join(list2)

        # Update the sentence
        sentence.Display = " ".join(words)
        sentence.Score -= 1



    def swap(self,sentence,word1,ch1,word2,ch2):
        sentence.History.append(sentence.Display)
        words=sentence.Display.split()
        a=words[word1][ch1]
        b=words[word2][ch2]
        new_words=[]
        if word1==word2:
            for i,word in enumerate(words):
                if i!=word1:
                    new_words.append(word)
                else:
                    #we have to crea a new word
                    new_word=''
                    for j,c in enumerate(word):
                        if j==ch1:
                            new_word+=word[ch2]
                        elif j==ch2:
                            new_word+=word[ch1]
                        else:
                            new_word+=c
                    new_words.append(new_word)
            new_sentence=' '.join(new_words)

        else:
            for i, word in enumerate(words):
                if i!=word1 and i!=word2:
                    new_words.append(word)
                elif i==word1:
                    new_word=''
                    for j,c in enumerate(word):
                        if j==ch1:
                            new_word+=b
                        else:
                            new_word+=c
                    new_words.append(new_word)
                elif i==word2:
                    new_word=''
                    for j,c in enumerate(word):
                        if j==ch2:
                            new_word+=a
                        else:
                            new_word+=c
                    new_words.append(new_word)
            new_sentence=' '.join(new_words)
        sentence.Display=new_sentence

    def undo(self,sentence):
        self.__repo.undo(sentence)

    def compute_score(self,sentence):
        self.__repo.compute_score(sentence)
    def select_random(self):
        return self.__repo.select_random()
    def scramble_sentence(self,sentence):
        self.__repo.scramble_sentence(sentence)


