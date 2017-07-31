readme

this repo has some DIY encryption that I am cooking up all by my lonesome (unless you join in!) it's all educational and all pretty non-functional. Enjoy some C++!

admin_password_challenges

A series of programming puzzles centered around the idea of faulty hashing or encryption implementations for you to exploit and break! Thwart Craig!

smoke_hash.cpp:
this is a simple example, you could have a hashing scheme where you said a=1, b=2, etc
it would just be terribly obvious to a basic newspaper reader

caesarshuffle_ENC.cpp:
uses a password to set an initial alphabet state for the cipher, and then uses the message to generate future states. it has 26! alphabet possibilities after being shuffled, the program makes rudimentary attempts to make sure that the plaintext does not match the encrypted text.

If your message had equivalent length to another common phrase, say HELLO THERE and GOODBYE BO - it may be possible to cook up two passwords that decrypt the same set of encrypted letters to different phrases, which increases the difficulty in cracking if you have no context.


caesarshuffle_DEC.cpp:
reverses the idea by finding the first letter using the password and then finding the appropriate alphabets using the plaintext as it goes.

cryptanalysis_challenge:
I'm going to try to crack my own corn (jimmy), but if you want to give it a shot I'd be thoroughly impressed that you cared enough to do it! caesar ciphers are not very resistant to brute force, but I think this one is a little bit more resistant because unless you know for certain that you have the correct first letter, the 2nd letter does not become clear, so if you fix letter 1 and say OK I think it is B for sure - you have to know the initial alphabet state (which is determined by a password). So if you've fixed the first letter to "B" you then have 25! alphabet permutations to try out in order to find the 2nd letter, and you could only go by context...

So the brute force method would be finding the first letter through guessing, trying out every alphabet permutation that puts the encrypted letter in the slot of that letter, for example if "F" was encrypted to "B" then you'd look at {1,F,3,4,5,6,...} (where the digits are permuted letters) - after generating the list of permutations you'd go down the decryption path using the fixed letter as the seed and seeing what you end up with at the end. It's only 15 septillion combinations after you fix that first letter! GL! If this is unclear, use cryptanalysis!


the point of the repo:
it gets you thinking about what hashes are, just another way to represent a message that is not necessarily reversible
what gets tough is resistance to cryptanalysis!

more to come later!
