#!/usr/bin/python3

class VigenereCipher(object):
    def __init__(self, key, alphabet):
        self.key = key
        self.alphabet = alphabet
        self.keylen = len(key)
        self.alphabetlen = len(alphabet)

    def encode(self, text):
        n = 0
        output = ""
        for i in text:
            if i in self.alphabet:
                k = self.alphabet.index(self.key[n % self.keylen]) #get current key iteration
                m = self.alphabet.index(i) #find index of letter to encode
                c = (m + k) % self.alphabetlen #encode letter
                output += self.alphabet[c] #concatenate encoded letter to output
                n += 1
            else:
                output += i
                n += 1
        return output

    def decode(self, text):
        n = 0
        output = ""
        for i in text:
            if i in self.alphabet:
                k = self.alphabet.index(self.key[n % self.keylen]) #get current key iteration
                m = self.alphabet.index(i) #find index of letter to decode
                c = (m - k) % self.alphabetlen #decode letter
                output += self.alphabet[c]
                n += 1
            else:
                output += i
                n += 1
        return output

def main():
    pass

if __name__=="__main__":
    main()
