# Antman
## _An Implementation of Huffman Algorithm_

The Huffman algorithm is a data compression algorithm that use binary manipulation to compress data based on occurences.

## Proof of quality

![set_image](https://github.com/Just1truc/Antman-EPITECH/blob/main/antman_proof.png)

Antman Project highest score of all time is ~70%

## Summary

- [How to make one](#explanation)
- [Installation](#installation)
- [Usage](#usage)
- [Make it a command](#use)

## How to make one <a name="explanation"></a>

The huffman algorithm is a method that compress files by replacing characters that appears often in the data by smaller binary codes.

So in the first place, you'll need to get a list of the occurencies of each data and from that data, build a binary tree.

#### Get occurency of each characters

Yes, in order to get the occurencies of each characters, we could just implement a list of 255 elements containing all ASCII characters and their respective occurencies but that would be really impractical.</br>
Furthermore, we would not need all of these characters most of the time.</br>
Consequently, considering the fact we are coding in C, lists are in a fixed size so we have to determine the size of the memory to alloc to the list.</br>
We are going to create a list of the occurency_list structure.

```c
typedef struct node {
    int occurency;
    char c;
    char *binary;
    struct node *right;
    struct node *left;
} node_t;

typedef struct occurency_list {
    node_t *node;
    int in_list;
} occurency_list_t;
```

*c* is the character.</br>
*occurency* is the occurency of the character in the data.</br>
*in_list* is something we gonna use later.</br>
Just set it to 0 for the time being.</br>
**right* is the right child node in the future binary tree.</br>
Same for **left* but for the left child.</br>

After that, we put the data into the list.

#### Build the binary tree

With that list of elements, we are going to fuse the elements into other elements to build the binary tree.

Basically, while there is more than 1 element that have is characteristic *in_list* to 0:

- select and keep the id of the 2 smallest elements in the list
ignoring the element with the *in_list* value to 1
- create a new node.
- put as the left node of that newly created node, the node of the first element and as the right node, the node of the second.
- Put that new node inside the pointer of the first element.
- Pass the *in_list* value of the second element to 1

Congratulation, the last element that have the *in_list* characteristic to 0 contain as a node the head of your tree.

#### Get binary values

Ok, now you have to build your binary tree.

To do so, just set a string of nothing and then browse through your tree:
- when you go to the right : add 1 at the end of the string.
- when you go to the left : add 0 at the end of the string.
- when you're on a node : just copy the string you currently have in the *binary* value of the node.

Alright, now you should have the binary value set for each node.

#### Encrypt

This part is pretty tricky. Indeed, we're gonna use some bit shifting.</br>
But why?</br>
First, you have to know that ASCII characters are signed and encoded on 7 bits. Bits are 0 or 1.</br>
So in ASCII : '0' = 48 = 0011 0000</br>
What we would do is basicly take the ASCII value of the encoded value of each character and put it in a char.</br>
Ex : '101' = 0000 0101</br>
We can do that multiple times :</br>
Taking the value we just got, we can add '11' inside of that ASCII value.</br>
Ex : 0000 0101 => 0001 0111</br>
So we just put 2 characters into an ASCII value that is a character. So with that method we can fit several characters into 1.</br>

#### Key Encryption

To decode Huffman encrypted data, we need the key to decode it.

The pattern used in the code is the following :

```
[Size of the size of the key][size of the key] ([char][size of the encoded][encoded binary of the key value] ) * nbr of elements
```

#### Decryption

Steps:
- Decrypt the key
- Transcrypt ASCII values to binary
- Decrypt the file character by character.

## Installation <a name="installation"></a>

To use this program, you'll need to install it first.

#### Clone Repository

In order to get the program, just use the following command where you want to clone the repository :

```bash
git clone git@github.com:Just1truc/Antman-EPITECH.git
```

Then you can go into it and build the program

```bash
cd Antman-EPITECH
make
```

Congrats, you're now ready to use it.

## Usage <a name="usage"></a>

#### Compress

To compress a file:

```bash
./antman file > compressed_file
```

#### Decompress

To decompress a file

```bash
./giantman compressed_file > uncompressed_file
```

## Make it a command <a name="use"></a>

If you like it, you surely want to use it anywhere in your pc right?</br>
If that's the case, go into the repository and then execute the following commands

```bash
cp antman /bin
cp giantman /bin
```

Now, in order to use them anywhere, just use them as commands.
