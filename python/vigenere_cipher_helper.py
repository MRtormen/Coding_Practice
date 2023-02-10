#!/usr/bin/python3
import click

class VigenereCipher(object):
    def __init__(self, key, alphabet):
        self.key = key
        self.alphabet = alphabet
        self.keylen = len(key)
        self.alphabetlen = len(alphabet)
        self.output = ""
        self.n = 0 # Will be used to find the current key iteration for each character to encrypt

    def get_values(self, i):
        # Find alphabet index of letter to encode
        m = self.alphabet.index(i) 
        # Get alphabet index of current key iteration
        k = self.alphabet.index(self.key[self.n % self.keylen])
        return m, k

    def encode(self, text):
        for i in text:
            if i in self.alphabet:
                m, k = self.get_values(i)
                c = (m + k) % self.alphabetlen # Encode letter
                self.output += self.alphabet[c] # Add encoded letter to output string
            else:
                self.output += i
            self.n += 1
        return self.output

    def decode(self, text):
        for i in text:
            if i in self.alphabet:
                m, k = self.get_values(i)
                c = (m - k) % self.alphabetlen # Decode letter
                self.output += self.alphabet[c] # Add decoded letter to output string
            else:
                self.output += i
            self.n += 1
        return self.output

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
    Tool to encode and decode Vinegere.
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
