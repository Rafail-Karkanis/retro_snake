This is the first exercise for "Advanced Programming", 
lectured by Thanasis Loukopoulos, Assistant Prof., Computer Science and Biomedical Informatics Dept., Univ. of Thessaly, Greece.
        Assisted by Panos K. Papadopoulos

Authors: Karkanis Rafail, Lialia Vasiliki

e-mails: rkarkanis@uth.gr, livasiliki@uth.gr

Programming Language: ISO/IEC 9899:2011

Theme of exercise: Retro Snake.

To run the code:

Windows:
cls && cl /W4 retro_snake.c movement.c list.c game.c board.c && retro_snake 10

Linux:
clear && gcc -Wall -ansi retro_snake.c movement.c list.c game.c board.c -o retro_snake.out && ./retro_snake.out 10