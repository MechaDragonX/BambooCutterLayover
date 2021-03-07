# Bamboo Cutter Layover

## What is Bamboo Cutter Layover?
Bamboo Cutter Layover is a simple CLI program written in C++ that takes a URL from a east Asian comic aggregation site (colloquialy a "manga reader" as most of the content on those websites are Japanese comics), and redirects it to [guya.moe](https://guya.moe), a robust comic book reader that focuses on a [specific series](https://en.wikipedia.org/wiki/Kaguya-sama:_Love_Is_War), using its proxy feature.

## How do I run it?
You can either compile from source or download the latest [releases](https://github.com/MechaDragonX/BambooCutterLayover/releases). Windows users that use Windows Subsystem for Linux, Cygwin, or MSYS2 can download the Unix builds, as these builds will work natively.

## What URL's are supported?
- [mangadex.org](https://mangadex.org)
- [nhentai.net](https://nhentai.net)
    - This is site is designed for users above the age of 18. I am not liable if you access this site illegally, due to being a minor or laws in your region regarding its content.
- [imgur.com](https://imgur.com)
- [readmanhwa.com](https://readmanhwa.com)

## Is it functional?
The program is functional but lacks some error checking and optimization. Please see the [releases page](https://github.com/MechaDragonX/BambooCutterLayover/releases) for compiled builds. Check the [issues](https://github.com/MechaDragonX/BambooCutterLayover/issues) tab for any issues.

## Coming Soon
- [Toonily](https://toonily.com) is a site that's supported by default, [but I am unable to get the proxy to work manually](https://github.com/MechaDragonX/BambooCutterLayover/issues/1).
- Add support for sites the use the [FoOlSlide reader](https://foolcode.github.io/FoOlSlide/), since [guya.moe](https://guya.moe) supports them.

## What the hell is this name?
The name is a reference to three things:
1. [*The Tale of the Bamboo Cutter*](https://en.wikipedia.org/wiki/The_Tale_of_the_Bamboo_Cutter), a classical Japanese novel/folktale
2. The Japanese comic book series, [*Kaguya-sama: Love is War*](https://en.wikipedia.org/wiki/Kaguya-sama:_Love_Is_War) (かぐや様は告らせたい ～天才たちの恋愛頭脳戦～, *Kaguya-sama wa Kokurasetai: Tensai-tachi no Ren'ai Zunōsen*, lit. "Kaguya Wants to Make Him Confess: The Geniuses' War of Hearts and Minds")
3. The song "Flight of the Bamboo Cutter" (竹取飛翔, *Taketori Hishou*) by DARK PHOENiX (a remix of a song from the [*Touhou*](https://en.wikipedia.org/wiki/Touhou_Project) series of videogames).
- The folktale focuses on a princess named Kaguya, a princess from the moon who was discovered as a baby in a bamboo stalk. As an adult, hery beauty attracts many suitors, all of whom she turns away with an impossible task. At the end of the story, she reveals that she is in fact from the moon and returns there.
- Many characters in modern Japanese fiction are influenced by Princess Kaguya, and the female protagonist of *Kagauya-sama*, Kaguya Shinomiya, is one example. Hence her name.
- As Princess Kaguya is often known as the "bamboo cutter", as she was raised by bamboo farmers, I took that and made the name a play on a connecting flight as opposed to a direct flight.
