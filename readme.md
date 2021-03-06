# Bamboo Cutter Layover

## What is Bamboo Cutter Layover?
Bamboo Cutter Layover is a simple CLI program written in C++ that takes a URL from a east Asian comic aggregation site (colloquialy a "manga reader" as most of the content on those websites are Japanese comics), and redirects it to [guya.moe](https://guya.moe), a robust comic book reader that focuses on a [specific series](https://en.wikipedia.org/wiki/Kaguya-sama:_Love_Is_War), using its proxy feature.

## How do I run it?
At the moment, you need to compile the source files to run it, as a result I can only confirm that the program works on Linux.
```shell
$ g++ bamboo_cutter_layover.cpp -o <output>
$ ./<output>
```
### Windows
- Windows Subsystem for Linux: Works perfectly
- Cygwin: Should work; untested
### macOS
Should work; untested

## Is it functional?
The program is functional but lacks error checking and optimization. Please see the [releases page](https://github.com/MechaDragonX/Majora/releases) for compiled builds when they are available. Check the [issues](https://github.com/MechaDragonX/Bheithir/issues) tab for any issues.

## What the hell is this name?
The name is a reference to three things:
- [*The Tale of the Bamboo Cutter*](https://en.wikipedia.org/wiki/The_Tale_of_the_Bamboo_Cutter) a classical Japanese novel/folktale
- The Japanese comic book series, [*Kaguya-sama: Love is War*](https://en.wikipedia.org/wiki/Kaguya-sama:_Love_Is_War) (かぐや様は告らせたい ～天才たちの恋愛頭脳戦～, *Kaguya-sama wa Kokurasetai: Tensai-tachi no Ren'ai Zunōsen*, lit. "Kaguya Wants to Make Him Confess: The Geniuses' War of Hearts and Minds")
- The song "Flight of the Bamboo Cutter" (竹取飛翔, *Taketori Hishou*) by DARK PHOENiX (a remix of a song from the [*Touhou*](https://en.wikipedia.org/wiki/Touhou_Project) series of videogames)
The folktale focuses on a princess named Kaguya, a princess from the moon who was discovered as a baby in a bamboo stalk. As an adult, hery beauty attracts many suitors, all of whom she turns away with an impossible task. At the end of the story, she reveals that she is in fact from the moon and returns there. Many characters in modern Japanese fiction are influenced by Princess Kaguya, and the femal protagonist of *Kagauya-sama*, Kaguya Shinomuya, is one example. Hence her name. As Princess Kaguya is often known as the "bamboo cutter", as she was raised by bamboo farmers, I took that and made the name a play on a connecting flight as opposed to a direct flight.
