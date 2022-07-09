# Datastructures in C

## Stack

To import stackA (stack implemented using arrays)

```C

#include "stack.h";

```

To compile the file

```bash

gcc -o <outputFile> <fileName.c> <pathTo'stack.c'>

```

To run the example c file,

```bash

cd "./in C/stack"

gcc -o example example.c stack.c

./example

```

## Binary Tree

To import Binary tree

```C

#include "binaryTree.h";

```

To compile the file

```bash

gcc -o <outputFile> <fileName.c> <pathTo'binaryTree.c'>

```

To run the example c file (pictureTree)

```bash

cd "./in C/tree"

gcc -o pictureTree pictureTree.c binaryTree.c ../stack/stack.c

./pictureTree

```

## AVL Tree

To import AVL Tree
```C
#include "AVLTree.h";
```

To compile the file
```bash
gcc -o <OutputFile> <fileName.c> <pathToAVLTree.c>
```

To run the example file
```bash
cd "./in C/tree/AVLTree"
gcc -o example.exe example.c AVLTree.c ../../stack/stack.c
./example
```
