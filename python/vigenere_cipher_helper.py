#!/usr/bin/python3
import click

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

def get_text(file):
    if file:
        text = open(file, "r").read()
    else:
        text = input("Input text: ")
    return text.replace(" ", "").lower()

@click.command()
@click.option("--file", "-f", help="Path to file")
@click.option("--key", "-k", required=True, help="Key to use for encoding/decoding")
@click.option("--mode", "-m", type=click.Choice(["e", "d"]), required=True, help="Choose mode, encode/decode")
def main(key, file, mode):
    """
    Tool to encrypt and decrypt Vinegere.
    """
    abc = "abcdefghijklmnopqrstuvwxyz"
    cipher = VigenereCipher(key, abc)
    text = get_text(file)
    if mode == 'e':
        output_text = cipher.encode(text)
    else:
        output_text = cipher.decode(text)
    click.echo(output_text)

if __name__=="__main__":
    main()
