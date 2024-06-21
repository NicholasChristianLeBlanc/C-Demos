// TavernGame2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Location.h"
#include "Player.h"
#include "Railroad.h"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main()
{
    // There is a LOT of text and such in this section
    #pragma region LOCATION/RIDE_SETUP

    Location* hub = new Location("The Hub", "The Hub connects all 4 parks at Walt Disney World in one place");

    Location* magicKingdomEntrance = new Location("Magic Kingdom", 
        "The heart and soul of Walt Disney World,"
        "\nthis was the only park area that was planned out by Walt Disney himself before he died,"
        "\nthe park originally opened on October 1st 1971.");

    Location* animalKingdomEntrance = new Location("Animal Kingdom", 
        "The fourth and most recent theme park to open at Walt Disney World,"
        "\nthe idea for Animal Kingdom came from Joe Rohde who had previously designed the Adventurers Club at Pleasure Island."
        "\nAnimal Kingdom first opened on April 22nd 1998.");

    Location* epcotEntrance = new Location("Epcot", 
        "The second park opened at Walt Disney World,"
        "\nthe original idea for EPCOT was for Disney to own its very own Experimental Prototype City Of Tomorrow,"
        "\ninstead, Epcot opened as a theme park on October 1st 1982.");

    Location* hollywoodStudiosEntrance = new Location("Hollywood Studios", 
        "The third park to open at Walt Disney World,"
        "\nthe park was created to directly compete with Universal Studios park that they were opening in Florida,"
        "\nHollywood Studios opened on May 1, 1989.");

    // Magic Kingdom
    Location* mainStreetUSA = new Location("Main Street USA", 
        "It smells like popcorn, vanilla and the scent of baking cookies!"
        "\nThe scents are so appetizing that you consider going into one of the many shops...");

    Location* emporium = new Location("The Emporium", 
        "Ah, a place where you can find almost anything Disney related including phone cases, mickey ears and t-shirts.");
    
    Railroad* railroad = new Railroad("Walt Disney Railroad", 
        "You wait for the next available train to arrive at the station."
        "\nIt doesn't take long before a beautiful red train with shining gold trim to make its way to the Station."
        "\nOnce onboard you hear a man's voice over the intercom: ");

    Location* castle = new Location("The Castle", 
        "The Castle itself appears to be build up out of gray brick with multiple spires that have a vibrant blue tiling."
        "\nthe main spire is tall and completely gold. The Castle surely is the most beautiful thing in all of Florida."
        "\nThe area in front of the Castle is circular with a statue of Walt Disney holding Mickey's hand located at the center."
        "\nOff the sides of the circle are pathways leading to different zones at the Magic Kingdom.");

    Location* adventureland = new Location("Adventureland", 
        "Part jungle, part tropical island and part desert oasis, looks like you've made your way to Adventureland!"
        "\nThis land has everything from the laughably punny Jungle Cruise, to the experience of being a pirate,"
        "\nthere's even spitting llamas! What more could you hope to experice?");

    #pragma region JUNGLE CRUISE
    Location* jungleCruise = new Location("Jungle Cruise", 
        "You board a dinky little boat suitable for a small group of about twenty or so people,"
        "\nthere is a skipper named Rob at the helm for this voyage"
        
        "\n\nSkipper Rob: "
        "\n\"My name is Rob, and I'll be your Jungle Cruise stripper- uh... skipper today here on the world famous Jungle Cruise."
        "\nI could also be your alligator wrestler and swimming instructor if you're not careful. So please be careful."
        "\nYou're going to go thru four of the world's mightiest rivers today."
        "\nYou're going to see things that you've never seen. "
        "\nYou're going to do things that you've never done. "
        "\nYou'll laugh, you'll cry, you'll... kiss ten and a half minutes goodbye...\""

        "\n\nOn your voyage Skipper Rob introduces you to a waterfall named \"Inspiration Falls\""
        
        "\n\nRob the stripper:"
        "\n\"Why is it called Inpiration Falls you ask?"
        "\nWell thats because it inspires sensible people to go further into the jungle silly!\""
        "\nSo you continue your adventure deeper into the jungle."
        
        "\n\nRob, who is a skipper: "
        "\n\"Over here we have a Python, We in the business call this guy Monty."
        "\nMonty the Python is over 26 feet long. But don't worry, he's friendly, And he might even get a crush on you.\""
        
        "\n\nThe next thing you see is a group of Gorrilas which has torn up somebody's camp,"
        
        "\n\nRob (the skipper dude): "
        "\n\"There's my base camp. My in-laws are visiting me from out of town again.\""
        "\n(Gesturing to the gorillas.) \"Hi mom, hi dad!\""
        "\n\"If any of you are wearing something yellow, don't make any sounds like a banana, okay?"
        "\nMy in-laws find that very a-pealing. Sorry, the jokes don't get any better.\""
        
        "\n\nSkipper Rob (doing skipper things):"
        "\n\"Well, do you know where you are now? It's the Nile river, which is the longest river in the world."
        "\nI think that it must have something to do with how it was named, because it just keeps going on for niles and niles."
        "\nIf you don't believe me, you are in de-nile."
        "\nAlright, moving on.\""

        "\n\nThere is an elephant sticking his head out of the foliage on the left."
        "\nIt whines noisily following your guide's last pun"

        "\n\nSkipper Rob Skipping Skipingly:"
        "\n\"Well, I'm glad someone gets it. "
        "\nThese are African Bull elephants. You can tell by their big floppy ears and rough trunks."
        "\nThey're really smart too. Listen.\""
        
        "\n\n(To elephant.) \"Speak!\""
        "\n\The Elephant whines."
        
        "\n\n\"Louder!\""
        "\nThe Elephant whines even louder this time."
        
        "\n\n\"Good, now spray everyone with water!\""
        "\nEveryone in the boat ducks down to avoid the drenching (including you), all to the amusment of your Guide."
        "\n\"Ha ha! Just kidding, just kidding. See, that's dry humor, get it? Dry hum... okay.\""
        
        "\n\nAligator Wrestler Rob: "
        "\n\"The next exciting experience you get to... experience? is A Rhino! He apparently chased a few guys up a tree."
        "\nBy the way, those gentlemen up in the tree are all members of the Hontus tribe."
        "\nI guess the rhino must be trying to poke-a-hontus."
        "\nSorry. The company makes me say it to push the movie.\""
        
        "\n\nBob:"
        "\n\"Oh, and over here. There's a couple of crocodiles. The big one's name is Dwayn, and he's really feisty."
        "\nSo please keep your hands and arms inside the boat, because I'd really hate to see one of you go down the dwayn.\""
        
        "\n\nRob (who is wearing a straw hat):"
        "\n\"Up ahead there are some natives. Although, "
        "\nI don't know if they're doing a funky new war dance or if they just lost the key to the men's room again."
        "\nOh, but don't worry. They'll only attack you if you're wearing a straw hat.\""

        "\n\nA group of the natives appear to be holding spears and have them aimed at the boat!"

        "\n\nScared Shitless Rob:"
        "\n\"Oh look out! Look out! We're being attacked! Get down get down get down! "
        "\nDon't worry about looking stupid, I'm doing that for you.\""

        "\n\nRobby Rotton: "
        "\n\"Ever wonder what the back side of water looks like?"
        "\nA lot like the front side. We're in Southeast Asia now on the Boing Makan River in Cambodia."
        "\nAh... and if you look up ahead, you will see a temple. I'm not sure what could be inside of it."
        "\nCould be anything from snakes to tigers."
        "\nI'll make an educated guess. Since we're at Disney World, it'll probably just be a gift shop. We'll check and see."
        "\nI just wanted to mention that it's going to be dark in there."
        "\nSo I want to remind you that my name is not Captain Stubing."
        "\nThis is not the Love Boat. Keep your hands to yourself.\""

        "\n\nAfter exiting the temple you are greeted by elephants! "
        
        "\n\nRobert (of the skipper kind):"
        "\n\"Okay, we're in the Indian Elephant bathing pool now. "
        "\nDon't worry, you can look. They're all wearing their trunks. "
        "\nAnd you can tell that these are Indian Elephants because:"
        "\nthey have smaller ears and smoother trunks than the Bull Elephants we saw earlier.\""

        "\n\nAs the boats near a dock for you to exit at, Skipperman Rob gives his conclusion speech:"
        "\n\"Uh, parents, there's one last thing that I'd like to mention before you leave. "
        "\nIt's kind of a sensitive subject to me."
        "\nWhen you leave the park later on today, please don't forget to take with you all of your small children."
        "\nUm, if you do happen to leave any of them behind,"
        "\nit only takes thirty days for them to become permanent property of the Walt Disney Company."
        "\nYou see, the kiddies will be shipped over to \"It's A Small World,\""
        "\ntheir little feet will be bolted to the floor and they'll be forced to sing that stupid song over and over again."
        "\nAnd after fifteen years, they will finally be eligible for a promotion to Jungle Cruise skipper."
        "\nYeah. Now you see how I got here."
        "\nSo if you see my parents wandering around the park, please send them over here and get me.\""

        "\n\nSkipper Rob:"
        "\n\"Okay, have you all had a great time on the Jungle Cruise today?!"
        "\nIf you had a good time, my name is Rob and this has been the world famous Jungle Cruise."
        "\nAnd if you had a lousy time... well, my name is Becky and this has been Space Mountain.\""
            
        "\n\nSkipper Rob's last words before you exit the boat:"
        "\n\"I'm really bad at goodbyes, so I'm going to make this simple for all of us."
        "\nGet out. Scram. Get the heck out of here."
        "\nEnjoyed having you... hope you enjoyed being had.\""
        
        "\n\nYou exit the boat after the boat has fully stopped and are now back in Adventureland,"
        "\njust five meters from where you were prior to entering the Jungle Cruise."
        "\nYeah, ten and a half minutes and you've only gone this far, congrats.", true);
    #pragma endregion JUNGLE CRUISE

    #pragma region POTC
    Location* piratesOfTheCaribbean = new Location("Pirates of the Caribbean",
        "\"Ahoy there, crew!"
        "\nFor your safety, remain seated, keeping your hands, arms, feet, and legs inside the boat-and watch your children."
        "\nAnd no flash pictures! Prepare to make sail!\""
        
        "\n\nYou start yer journey by boarding your sea-ready vessel big enough to hold twenty three or twenty four people on board."
        "\nAs the vessel makes a large right turn you can hear a voice repeating \"Dead Men Tell No Tales\" and you see smoke ahead."
        "\nOn the smoke you see a face, as your boat gets closer the face and smoke dissipates."
        
        "\n\nThe other side of the smoke has the appearence of a cave, the walls shimmering a beautiful blue."
        "\nDirectly in front of you appears to be a shipwreck that has taken the lives of three pirates,"
        "\nOne skeleton lays on its back with a cutlass standing straight up, it looks like somebody tried to dig a grave for him."
        "\nAnother lays face down and appears to have met the same fate, seems like they were trying to escape something..."
        "\nThe third pirate stands with its back to the wall, a cutlass holding him upright."
        "\nAmong the skulls there also lays a broken sail, a treasure chest, a barrel (presumably filled with rum) and a lanturn."
        
        "\n\nYour ship makes a slight right and passes by the deceased pirates,"
        "\non your right it looks like the cave opens to a full shipwreck, the wheel still intact and a skeleton stands holding it."
        "\nThere seems to be a storm going on and the rain is coming down hard."
        
        "\n\nYour ship continues on, making a left turn you see complete pitch black ahead of you where the track should be,"
        "\na skeleton head is visible above the void of track,"
        
        "\n\nThe Skeleton speaks:"
        "\n\"Ye come seekin' adventure and salty old pirates, eh?"
        "\nSure, you come to the proper place. "
        "\nBut keep a weather eye open, mates, and hold on tight-with both hands, if you please. "
        "\nThere be squalls ahead! And Davy Jones waiting for them that don't obey."
        
        "\n\nThe skeleton's eyes flash blinding you for a brief second before plunging you down a 13-foot drop into darkness."
        "\nYour vessel makes a left turn and as it does so, you can see a ship on your left shooting its cannons at a fortress,"
        
        "\n\nCaptain Barbossa stands attop the ship yelling:"
        "\n\"Strike your colors, ya bloomin' cockroaches!"
        "\nSurrender Cap'n Jack Sparrow-or, by thunder, we'll burn this city to the ground!"
        "\nThey needs persuasion, mates... Fire at will!"
        "\nIt's Cap'n Jack Sparrow we're after-and a fortune in gold."
        "\nPut up your white flag, ya scurvy scum. Bring me Cap'n Jack Sparrow, or I'll be sendin' ya to Davy Jones!\""
        
        "\n\nThe cannons barrels light up as the cannon bursts backwards with a boom, both fire at one another,"
        "\nyou hear a cannon ball falling as a splash of water goes off on the left side of your boat, you feel the spray of it."
        
        "\n\nYour boat rounds a corner to see a Captor Pirate instructing his Lackey to dunk Carlos,"
        "\nthe town magistrate, into a well in an effort to make him talk."
        "\nMeanwhile, Carlos' Wife watches from the window of their home above."
        "\nAt the same time A Musician Pirate plays the flute and Captain Jack can be seen hiding next to the scene."
        
        "\n\nCaptor Pirate:"
        "\n\"Pipe the lubber aloft, matey."
        "\nWhere be Cap'n Jack Sparrow and the treasure, ya bilge rat?!\""
        
        "\n\nCarlos' Wife:"
        "\n\"Don't tell him, Carlos! No, no, no, no!\""
        
        "\n\nA Pirate holding a rifle shoots at her. She screams and disappears behind the shutter."
        
        "\n\nRifle Pirate:"
        "\n\"Hahaha, scuttle, ya bilge rat!\""
        
        "\n\nCarlos (while getting dunked):"
        "\n\"No! No! I'll talk! No! No! No!\""
        
        "\n\nCaptor Pirate:"
        "\n\"Take him aloft again, matey!\""
        
        "\n\nWhile they carry Carlos up out of the water, Carlos' Wife speaks again:"
        "\n\"Be brave, Carlos! Don't listen to him!\""
        
        "\n\nThe Rifle Pirate shoots at her again then laughs."
        
        "\n\nCaptor Pirate:"
        "\n\"Where be Cap'n Jack Sparrow?"
        "\nSpeak up-or do you fancy a swim with Davy Jones?!\""
        
        "\n\nCarlos' Wife:"
        "\n\"Don't tell him, Carlos! Don't be chee-cken!"
        
        "\n\nThe Rife Pirate shoots at her again as Carlos gets dunked into the well for a second time."
        
        "\n\nCarlos:"
        "\n\"I am no chee-cken! I will not talk!\""
        
        "\n\nAs Carlos gets dunked for a third time your boat moves on to the next scene, his gurgles being the last sound heard."
        "\nThe next scene you can see a group of pirates off to the right side of your boat,"
        "\nas well as an Auctioneer and a redheaded pirate named Redd"
        
        "\n\nAuctioneer:"
        "\n\"Now you scurvy scum, do I hear ten? A hen for a ten?\""
        
        "\n\nPirate:"
        "\n\"Ten, I'll give ya twenty... for the rum!\""
        
        "\n\nAuctioneer: "
        "\n\"Pipe down you lilly-livered lubber."
        "\nStrike yer feathers dearie, show em yer flock.\""
        
        "\n\nRedd:"
        "\n\"Eh, send them hens to Davey Jones. It's the rum they want!\""
        
        "\n\nPirates:"
        "\n\"Yeh, the rum!\""
            
        "\n\nRedd:"
        "\n\"Ha, ha, ha. Drink up me hearties, yo ho!\""
            
        "\n\nAuctioneer:"
        "\n\"Quiet ye scum! (gunshots)"
        "\nWeigh anchor now ye swabbies, what be I offered for these hearty hens? Everyone an egg layer?\""
            
        "\n\nOne Of The Pirates:"
        "\n\"Not lest they be layin golden eggs.\""
            
        "\n\nAuctioneer:"
        "\n\"Belay there ye bilge rat!\""
            
        "\n\nRedd:"
        "\n\"Oh quit yer cluckin' the gentlemen want the rum, don't ya boys?\""
            
        "\n\nPirates:"
        "\n\"We wants the rum!\""
            
        "\n\nYour boat goes under a bridge to a chase scene."
        "\nYou can see a Map Pirate sitting atop a barrel with the treasure map spread across his lap and key in his hand."
        "\nCaptain Jack Sparrow pops out from the barrel behind him to look over his shoulder."
        "\nMap Pirate's Dog keeps barking whenever he appears."
            
        "\n\nMap Pirate:"
        "\n\"Oh, it's the treasure map for sure, and no mistake."
        "\nAnd by thunder, that scoundrel Cap'n Jack Sparrow will never lay eyes on it-nor this here key neither, ha har.\""
        "\n(Dog barks.) \"Quiet! Ha har, fooled him, I did, by gum!"
        "\nI tell you once, Cap'n Jack Sparrow-you'll never find the treasure without a look at this here map... "
        "\nand this lovely key to the treasure room. Hahahaha!\""
        "\n(Dog barks.) \"Easy boy. Here I be-holdin' the treasure map, and the key as well."
        "\nWhat I wouldn't give to see the look on Cap'n Jack Sparrow's face when he hears tell 'tis only me what's got the goods.\""
        "\n(Dog barks.) \"Keep still! I'm studyin' me map!\" (Dog barks.)"
            
        "\n\nYour boat passes by Old Bill with two Stray Cats."
        "\nOld Bill:"
        "\nHere, kitty, kitty, kitty! Hehehe, have a nice little tot of rum with Old Bill, eh? Hehehe...\""
        "\n(Cats meow shrilly.) \"Come on, now-be a nice little pussycat!\""
        "\n(He laughs and coughs.) \"Oh, you be a feisty one, you be.\" (CATS meow angrily.)"
            
        "\n\nYour boat passes under another bridge and by a Pirate Trio singing with a Dog and a Donkey."
        "\nNext, you pass by the city being burned while Pirates loot."
        
        "\n\nThe Pirates sing as your boat passes by:"
        "\n\"Yo ho, yo ho, a pirate's life for me!"
        "\nWe pillage, we plunder, we rifleand loot."
        "\nDrink up me hearties, yo ho!"
        "\nWe kidnapand ravageand don't give a hoot."
        "\nDrink up me hearties, yo ho!\""

        "\n\n\"Yo ho, yo ho, a pirate's life for me!"
        "\nWe extort, we pilfer, we filchand sack."
        "\nDrink up me hearties, yo ho!"
        "\nMaraud and embezzleand even hijack."
        "\nDrink up me hearties, yo ho!\""

        "\n\n\"Yo ho, yo ho, a pirate's life for me!"
        "\nWe kindleand char; inflameand ignite."
        "\nDrink up me hearties, yo ho!"
        "\nWe burn up the city; we're really a fright."
        "\nDrink up me hearties, yo ho!\""

        "\n\n\"We're rascalsand scoundrels.We're villainsand knaves."
        "\nDrink up me hearties, yo ho."
        "\nWe're devilsand black sheep.We're really bad eggs."
        "\nDrink up me hearties, yo ho.\""

        "\n\n\"Yo ho, yo ho, a pirate's life for me!"
        "\nWe're beggarsand blightersand ne'er - do - well cads,"
        "\nDrink up me hearties, yo ho!"
        "\nAye, but we're loved by our mommiesand dads,"
        "\nDrink up me hearties, yo ho!\""

        "\n\nNext, you pass by a very Muddy Pirate snoring next to Pigs."
        "\nYou pass under another bridge, where a Hairy Legged Pirate's foot hangs down from right above your head."
            
        "\n\nYoy pass under another (and final) bridge and into jail scene."
        "\nsix Jail Pirates are in two jail cells, three to the Left and three to the Right."
        "\nOutside the left cell, a Dog holds onto the keys to the cells."
        "\nThe Jail Pirates attempt to coax the key from him."
        
        "\n\nLeft Pirate #1:"
        "\n\"Grab his tail! Go on, grab it!\""
            
        "\n\nLeft Pirate #2;"
        "\n\"Don't scare him!\""
        
        "\n\nRight Pirate #1:"
        "\n\"There you go, dearie. Come on-have a nice bone, eh? That's a good lad! Come on, now!\""
            
        "\n\nLeft Pirate #1:"
        "\n\"Oooh, steady now. Steady, steady. Here, that's it. Take the keys off his ruddy neck.\""
            
        "\n\nRight Pirate #1:"
        "\n\"It's us what needs your ruddy 'elp, not them blasted lubbers!\""
            
        "\n\nRIGHT PIRATE #2:"
        "\n\"Oh, that blasted pocket - pickin' pirate!\""
            
        "\n\n(Left Pirate #3 whistles for the Dog.)"
            
        "\n\nLeft Pirate #1:"
        "\n\"Bring Old Bill them nice keys!\""
            
        "\n\nRight Pirate #2:"
        "\n\"Blasted blackhearted cur!\""
            
        "\n\nLeft Pirate #2:"
        "\n\"Here you be, Spot. How's about a nice, juicy bone?\""
            
        "\n\nLeft Pirate #1:"
        "\n\"Over 'ere, Spot! Over 'ere. Now, easy boy!\""
            
        "\n\nLeft Pirate #2:"
        "\n\"Here, give us the keys, you scrawny little beast!\""
            
        "\n\nRight Pirate #1:"
        "\n\"I say grab his ears.\""
            
        "\n\n(Left Pirate #3 keeps whistling.)"
            
        "\n\nLeft Pirate #2:"
        "\n\"Walk him over to the noose. "
        "\nCome on, now! Hold it higher. "
        "\nHigher, I say! Higher!\""
            
        "\n\nRight Pirate #1:"
        "\n\"Ugh, mangy mutt! Hit him with a soup bone!\""
            
        "\n\nLeft Pirate #1:"
        "\n\"Here, doggy. Here, here, doggy! Nice doggy!\""
            
        "\n\nRight Pirate #2:"
        "\n\"Belay that talk. We want the keys, not the mutt, you swab.\""
            
        "\n\nRight Pirate #1:"
        "\n\"Can't you reach any further, you stub - winged bilge rat?\""
            
        "\n\nYour boat makes a left turn, you pass Captain Jack Sparrow sitting in the treasure room surrounded by gold and jewels."
            
        "\n\nCaptain Jack Sparrow:"
        "\n\"Drink up me hearties, yo ho!"
        "\nYo ho, yo ho, a pirate's life for me!\""

        "\n\n\"I raise a toast to all of our many shipmates lost at sea. Salut, mes amis!\""

        "\n\n\"Drink up me hearties, yo ho!"
        "\nRascals and scoundrels; villainsand knaves."
        "\nDrink up me hearties, yo ho."
        "\nWe're devilsand black sheep. We're really bad eggs."
        "\nDrink up me hearties, yo ho.\""

        "\n\n\"Drink up, lads! There's treasure enough for all."
        "\nI shall take this paltry sum as a stipend to cover my expenses... and the chest of jewels.\""

        "\n\n\"Drink up me hearties, yo ho!"
        "\nYo ho, yo ho, a pirate's life for me!\""

        "\n\n\"A toast to piracy, and its many shiny rewards. As a career, what could be more rewarding?\""

        "\n\n\"Drink up me hearties, yo ho!\""

        "\n\n\"I humbly accept this magnificent treasure as my reward for a life of villainy, larceny, skullduggery, and persnickety.\""
            
        "\n\nAs you near the end of the ride station a safety message is played:"
        "\n\"When the boat stops, please be steppin' out to yer right."
        "\nAll hands, prepare to go ashore by steppin' out to yer right.\""
            
        "\n\nYou make your way off the ride safely and are now back in Adventureland.", true);
    #pragma endregion POTC

    #pragma region TIKI ROOM
    Location* tikiroom = new Location("Enchanted Tiki Room", 
        "You enter the Tiki Room and take a seat, a cast member comes in and gives spiel and then wakes up Jose."
        
        "\n\nJose:"
        "\n\"Ah, buenos dias, senorita. "
        "\nMy siestas are getting are getting chorter and chorter."
        "\nOh, look at all the people! "
        "\nWelcome to Walt Disney's Enchanted Tiki Room."
        "\nHey, Michael, mi amigo! Pay attention-it's showtime.\""
        
        "\n\nMichael:"
        "\n\"So it is. And what darling people I have sittin' under me."
        "\nPierre, you rascal, you! Let's put on the show.\""
        
        "\n\nPierre:"
        "\n\"Mon ami, I am always ready, as you say, to put on ze show.\""
        "\n(Whistles.)"
        "\n\"Oh pardon, madame, that whistle was for my good friend Fritz.\""
        
        "\n\nFritz:"
        "\n\"Ach tu lieber!"
        "\nI almost fell out of mein upper perch."
        "\nGlad to see you all aboard-uh, ashore-or-\""
        "\n(Laughs.)"
        "\n\"Verever you are!"
        "\nMein goodness, you're all shtaring at us."
        "\nWe better shtart the show rolling!\""
        
        "\n\nMichael:"
        "\n\"Wait! Wait!"
        "\nWe forgot to wake up the glee club!\""
        
        "\n\n(Whistle blows, followed by loud squawking from the birds.)"
        
        "\n\nJose:"
        "\n\"Ole! Ole!"
        "\nIt's showtime!\""
        
        "\n\nChorus:"
        "\n\"In the Tiki, Tiki, Tiki, Tiki, Tiki Room,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room.\""
        
        "\n\nJose:"
        "\n\"All the birds sing words,\""
        
        "\n\nMichael:"
        "\n\"And the flowers croon,\""
        
        "\n\nChorus:"
        "\n\"In the Tiki, Tiki, Tiki, Tiki, Tiki Room!\""
        
        "\n\nJose:"
        "\n\"Welcome to our tropical hideaway,"
        "\nYou lucky people, you!"
        "\nIf we weren't in the show, starting right away,"
        "\nWe'd be in the audience too!\""
        
        "\n\nChorus:"
        "\n\"All together!"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room.\""
        
        "\n\nJose:"
        "\n\"All the birds sing words,\""

        "\n\nMichael:"
        "\n\"And the flowers croon,\""

        "\n\nChorus:"
        "\n\"In the Tiki, Tiki, Tiki, Tiki, Tiki Room!\""
        
        "\n\nMichael:"
        "\n\"I sing so beautiful-I should sing solo!\""
            
        "\n\nJose:"
        "\n\"Si... So low we can't hear you!\""
        
        "\n\nPierre:"
        "\n\"My voice may not be so marvelous, but my profile is out of zis world!\""
        
        "\n\nFritz:"
        "\n\"Jawohl, but the trouble is it's not far enough out of this world. Isn't that right, Herr Schmidt?"
        "\nOh-ho, I see-Schmidt has no hair!\""
        
        "\n\nJose:"
        "\n\"Mi amigos, stop the clucking. You sound like a bunch of old hens."
        "\nThere's a lot of birds waiting to go on. For instance...\""
        
        "\n\nMichael:"
        "\n\"The boys in the back are kamikaze.\""
        
        "\n\nJose:"
        "\n\"Because of their claws?\""
        
        "\n\nMichael:"
        "\n\"No-because they're macaws!"
        "\nAnd our fine feathered friend is a jolly toucan."
        "\nAnd two can sound better than one toucan can.\""
        
        "\n\nJose:"
        "\n\"The bird of paradise is an elegant bird."
        "\nIt likes to be seen, and it loves to be heard."
        "\nMost little birdies will fly away,"
        "\nBut the Tiki Room birds are here everyday.\""
            
        "\n\nChorus:"
        "\n\"All together!"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room.\""

        "\n\nJose:"
        "\n\"All the birds sing words,\""

        "\n\nMichael:"
        "\n\"And the flowers croon,\""

        "\n\nChorus:"
        "\n\"In the Tiki, Tiki, Tiki, Tiki, Tiki Room!\""
            
        "\n\nMichael:"
        "\n\"Our show is delightful, we hope you'll agree."
        "\nWe hope that it fills you with pleasure and glee."
        "\nBecause if we don't make you feel like that, we're gonna wind up on a lady's hat!"
            
        "\n\nChorus:"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room.\""
            
        "\n\nJose:"
        "\n\"All the birds sing words,\""

        "\n\nMichael:"
        "\n\"And the flowers croon,\""

        "\n\nChorus:"
        "\n\"In the Tiki, Tiki, Tiki, Tiki, Tiki Room!\""
            
        "\n\nJose:"
        "\n\"Our magnificent production is yet to come, so strum the guitar and beat the drum!"
        "\nWe've been a hit, and we know you adore us, so come on and join us in another chorus!"
            
        "\n\nChorus:"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room.\""
            
        "\n\nJose:"
        "\n\"A little softer!\""
            
        "\n\nChorus:"
        "\n\"All the birds sing words, and the flowers croon,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room!\""
            
        "\n\nJose:"
        "\n\"A little louder!\""
            
        "\n\nChorus:"
        "\n\"In the Tiki, Tiki, Tiki, Tiki, Tiki Room,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room."
        "\nAll the birds sing words, and the flowers croon,"
        "\nIn the Tiki, Tiki, Tiki, Tiki, Tiki Room!\""
            
        "\n\n(The song ends.)"
            
        "\n\nJose:"
        "\n\"Let's give the little birdies a great big hand!\""
            
        "\n\nPierre:"
        "\n\"Oui.Applaud, applaud!\""
            
        "\n\nFritz:"
        "\n\"Ja!You down there-mit both hands!\""
            
        "\n\nJose:"
        "\n\"And now, senorsand senoritas, please place your eyes into the center-of the room, that is."
        "\nWe present the enchanted fountain.\""
            
        "\n\nFritz:"
        "\n\"Ach, ja! And the wunderbar bird mobile... Which has birds on it."
        "\nAnd it goes roundand round."
        "\nUnd dat's why they call it a bird mobile.\""
            
        "\n\nMichael:"
        "\n\"Look, here come the girls!\""
            
        "\n\nPierre:"
        "\n\"Madames and monsieur-introducing the lovely ladies of the ensembles."
        "\nJust like the Follies Bergère with all the feathers."
        "\nThere's Collette! Allo, Collette."
        "\nSuzette! Allo, Mimi! Gigi! Fifa! Hehe, oh Fifi!\""
            
        "\n\nJose:"
        "\n\"I wonder what happened to Rosita...\""
            
        "\n\nBird Mobile:"
        "\n\"Let's all sing like the birdies sing:"
        "\nTweet, tweet, tweet, tweet, tweet."
        "\nLet's all sing like the birdies sing:"
        "\nSweet, sweet, sweet, sweet.\""

        "\n\n\"Let's all warble like nightingales."
        "\nGive your throat a treat."
        "\nTake your time from the birds,"
        "\nNow you all know the words:"
        "Tweet, tweet, tweet, tweet, tweet.\""
            
        "\n\nJose:"
        "\n\"Let's all sing like the birdies sing"
        "\nBuh-buh-buh, buh buh-buh-buh, buh buh!\""
            
        "\n\nFritz:"
        "\n\"Let's all sing like the birdies sing,"
        "\nTweet, tweet, tweet-"
        "\nMy, that bird sings sweetly!\""
            
        "\n\nPierre:"
        "\n\"Let's all warble like nightingales-"
        "\nAh, Mimi, c'est magnifique!"
        "\nTake your time from ze birds,"
        "\nNow you all know ze words."
        "\nSing along with us!\""
            
        "\n\nJose:"
        "\n\"Now we want you people down there to sing along with us birds up here."
        "\nAll together now."
        "\nLet's all sing like the birdies sing.\""
            
        "\n\nChorus:"
        "\n\"Let's all sing like the birdies sing,\""

        "\n\nJose:"
        "\n\"Tweet, tweet, tweet, tweet, tweet.\""

        "\n\nChorus:"
        "\n\"Tweet, tweet, tweet, tweet, tweet.\""

        "\n\nJose:"
        "\n\"Let's all sing like the birdies sing.\""

        "\n\nChorus:"
        "\n\"Let's all sing like the birdies sing,\""

        "\n\nJose:"
        "\n\"Sweet, sweet, sweet, sweet, sweet.\""

        "\n\nChorus:"
        "\n\"Sweet, sweet, sweet, sweet, sweet.\""

        "\n\nJose:"
        "\n\"Let's all warble like nightingales,\""

        "\n\nChorus:"
        "\n\"Let's all warble like nightingales,\""

        "\n\nJose:"
        "\n\"Give your throat a treat!\""

        "\n\nChorus:"
        "\n\"Give your throat a treat.\""

        "\n\nJose:"
        "\n\"Take your time from the birds,\""

        "\n\nChorus:"
        "\n\"Take your time from the birds,"
        "\nNow you all know the words:"
        "\nTweet, tweet, tweet, tweet, tweet.\""

        "\n\nJose:"
        "\n\"Everybody whistle!\""

        "\n\n(Everyone whistles until the end of the song.)"
            
        "\n\nJose:"
        "\n\"Applause! Applause!"
        "\nThat's so good!\""

        "\n\nFritz:"
        "\n\"Wunderbar! Wunderbar!"
        "\nGive yourself a hand!\""

        "\n\nPierre:"
        "\n\"Ah, zat was magnifique!\""

        "\n\nJose:"
        "\n\"Si, no one laid an egg but me.\""

        "\n\nMichael:"
        "\n\"And now, ladiesand gentlemen, we have something really big for you.\""

        "\n\nFritz:"
        "\n\"Ja, the birds schtand schtill, und the Tiki Room flies away!\""

        "\n\nPierre:"
        "\n\"Mon ami, quit talking while I'm interrupting."
        "\nLadiesand gentlemen, now we present-direct from the islands-a musical luau!\""
            
        "\n\nFlowers:"
        "\n\"Tahuwai la a tahuwai wai la,"
        "\nEhu hene la a pili koo lua la,"
        "\nPututui lu a ite toe la,"
        "\nHanu lipo ita paalai.\""

        "\n\n\"Tahuwai la a tahuwai wai la,"
        "\nEhu hene la a pili koo lua la,"
        "\nPututui lu a ite toe la,"
        "\nHanu lipo ita paalai.\""

        "\n\n\"Au we ta huala,"
        "\nAu we ta huala.\""

        "\n\n\"Tahuwai la a tahuwai wai la,"
        "\nEhu hene la a pili koo lua la,"
        "\nPututui lu a ite toe la,"
        "\nHanu lipo ita paalai.\""

        "\n\n\"Tahuwai la a tahuwai wai la,"
        "\nEhu hene la a pili koo lua la,"
        "\nPututui lu a ite toe la,"
        "\nHanu lipo ita paalai.\""

        "\n\n\"Au we ta huala,"
        "\nAu we ta huala."
        "\nHuala, huala, huala.\""

        "\n\n(Tiki idols begin drumming and chanting."
        "\nThe flowers join in for a reprise of \"Hawaiian War Chant.\" Song climaxes in rain and thunder.)"
            
        "\n\nFritz:"
        "\n\"Ach, somebody has schtolen my thunder!\""

        "\n\nJose:"
        "\n\"I think someone has left the chower running.\""

        "\n\nMichael:"
        "\n\"Be careful, me fine friends."
        "\nThe gods have been angered by all the celebratin'!"
        "\nBut, me buckos, every cloud has a silver lining.\""

        "\n\nPierre:"
        "\n\"Monsieurs et madames, it's time to say adieu."
        "\nBut we hope you will always remember the amazing things which happened here in Walt Disney's Enchanted Tiki Room.\""

        "\n\nChorus:"
        "\n\"The birdies had their fling."
        "\nYou've heard the flowers sing."
        "\nTikis play the drums."
        "\nHear them do the chant."
        "\nFarewell, and aloha to you!\""

        "\n\nJose:"
        "\n\"Ole! Ole! Applause!"
        "\nLet's give the birds a standing ovation! Applause!"
        "\nUp, up, down there! Applause!"
        "\nEverybody stand up on your feet! Ole!\""

        "\n\nMichael:"
        "\n\"And now, as long as you're all standin'...\""

        "\n\nJose:"
        "\n\"We have a wonderful magic trick for you.\""

        "\n\nFritz:"
        "\n\"Ja, a wunderbar trick!"
        "\nEverybody, face the door, und the trick is, ve gonna make you all... disappear!\""

        "\n\nChorus:"
        "\n\"Heigh ho. Heigh ho."
        "\nIt's out the door you go."
        "\nWe hope you've all enjoyed the show."
        "\nHeigh ho. Heigh ho, heigh ho.\""

        "\n\n\"Heigh ho. Heigh ho."
        "\nKeep marching in a row,"
        "\nDon't stop to look or read a book,"
        "\nHeigh ho. Heigh ho, heigh ho.\""

        "\n\n\"Heigh ho. Heigh ho."
        "\nJust lift your feetand go."
        "\nWe'll sing this song; you march along!"
        "\nHeigh ho. Heigh ho, heigh ho.\""

        "\n\n\"Heigh ho. Heigh ho."
        "\nStep lively—not so slow!"
        "\nCome back again; we'll see you then."
        "\nHeigh ho. Heigh ho, heigh ho.|"""

        "\n\n\"Heigh ho. Heigh ho."
        "\nMake room for our next show!"
        "\nThere's folks outside; go take a ride."
        "\nHeigh ho. Heigh ho, heigh ho.\""

        "\n\n\"Heigh ho. Heigh ho."
        "\nIt's out the door you go!"
        "\nWe hope you've all enjoyed the show."
        "\nHeigh ho! Heigh ho!\""
            
        "\n\nYou exit the doors back outside to Adventureland after thoroughly enjoying the Tiki Room.", true);
    #pragma endregion TIKI ROOM

    #pragma region ALADDIN
    Location* carpets = new Location("The Magic Carpets of Aladdin", 
        "Aladdin:"
        "\n\"Hey, magic carpet riders-this is Aladdin."
        "\nTo make sure your magic carpet ride is a safe one, "
        "\nI want to remind you to stay seated with your seatbelt fastened nice and tight throughout your flight."
        "\nAnd hey, everybody-make sure you keep your hands, arms, feet, and legs inside. And be sure to watch your kids!\""
        
        "\n\nAfter you board your carpet Aladdin speaks again:"
        "\n\"Now, if you wanna make your carpet fly higher or lower,"
        "\nriders in the front row can push up or pull down on the lever. "
        "\nTo make your carpet tip forward or back, riders in the back row can press that magic scarab. "
        "\nIs everyone ready? Then let's fly to Agrabah!\""
        
        "\n\nThe ride starts up and your carpet starts to move forward in a circular motion,"
        "\nit rises and lowers as the ride goes on, and you even have a camel spitting water at you."
        
        "\n\nAfter a little while Aladdin speaks again:"
        "\n\"Okay everyone, we're coming in for a landing!"
        "\nPlease stay seated until your magic carpet comes to a complete stop. Then walk to the nearest exit."
        "\nHope you had a magical ride. See ya soon!\"", true);
    #pragma endregion ALADDIN

    Location* frontierland = new Location("Frontierland", 
        "Ah, Frontierland, themed to mimic the architecture of the American West you can see 2 of the most iconic rides here."
        "\nOn your left is Splash Mountain, every couple seconds you see a log full of guests screaming down it's 52 foot drop."
        "\nAnd on your right you see the entrance for Big Thunder Mountain, the wildest wide in all the wilderness!!");

    #pragma region SPLASH MOUNTAIN
    Location* splashMountain = new Location("Splash Mountain", 
        "\"For your safety, please stay seated with your hands, arms, feet, and legs inside the log. And be sure to watch your kids!"
        "\nHave a zip-a-dee-doo-dah ride!\""
        
        "\n\nYou board your log suitable for 8 guests to fit comfortably,"
        "\nthe log begins to move forward and imediately makes a right turn onto a lift hill."
        
        "\n\nBr'er Frog:"
        "\nFolks hereabouts say Br'er Rabbit's leavin' home."
        "\nI say he's headin' for trouble."
        "\nMark my words-Br'er Rabbit's gonna put his foot in Br'er Fox's mouth one of these days."
        "\nSooner than later, Br'er Fox and Br'er Bear gonna catch that Br'er Rabbit for sure."
        
        "\n\nYour log goes over first hill and around bend,"
        "\non your right is a large drop that you can see other guests go screaming down."
        "\nYour log makes it to a second lift hill,"
        "\nbut not before a water jet causes you to get wet after another log goes over the large drop."
        
        "\n\nMusic changes to banjo version of \"How Do You Do?\" as Bees buzz and then Br'er Rabbit begins singing."
        "\nYour log goes around another bend while listening to the music, you see a sign pointing out 3 locations:"
        "\n - Bre'er Foxes Lair"
        "\n - Chick-A-Pin Falls"
        "\n - The Laughing Place"
        "\nAll of which are pointing in the direction you are headed in."
        
        "\n\nThe log makes another right turn and you have a great view of Frontierland before the turn is over,"
        "\nat the end of the bend you face the first drop of Splash Mountain, Slippin Falls."
        "\nYour log goes over the drop and you get a decent little splash of water."
        
        "\n\nYour log goes into The Fishing Place, where frogs and fishing birds take over singing:"
        "\n\"How do you do? Mighty pleasant greetin'."
        "\nHow do you do?  Say it when you're meetin'."
        "\nHow do you do? With every one repeatin'"
        "\nPretty good, sure as you're born.\""
        "\n(Howdy!)"

        "\n\n\"What goes up is sure to come down."
        "\nA penny lost is a penny found."
        "\nHow do you do?"
        "\nAnd you howdy back."
        "\nA little bit of this and a little bit of that.\""

        "\n\n\"How do you do?\""
        "\n(Pleased to meet ya!)"
        "\nFine, how are you?\""
        "\n(Nice seein' ya!)"
        "\nHow you come on?\""
        "\n(How you come on?)"
        "\n\"Pretty good, sure as you're born.\""

        "\n\n\"Stop jumpin' around,"
        "\nYou'll run out of breath!"
        "\nWhy don't you sit back"
        "\nAnd calm yourself?\""

        "\n\n\"You can hurry on now if you must."
        "\nWe'll do what we like, 'cause"
        "\nThat suits us.\""
        "\n(Howdy!)"

        "\n\n\"How do you do ? Mighty pleasant greetin'."
        "\nPretty good, sure as you're born.\""
        "\n(Howdy!)"
        "\n\"Pretty good, sure as you're born.\""
        "\n(Howdy do!)"

        "\n\n\"How do you do? Mighty pleasant greetin'."
        "\nHow do you do? Say it when you're meetin'."
        "\nHow do you do? With every one repeatin'"
        "\nPretty good, sure as you're born."
        "\nPretty good, sure as you're born.\""

        "\n\n\"The weather is good, the fishin' is fine."
        "\nOh, what do we do with all of our time ?"
        "\nWell, we sitand we thinkand we wiggle our toes."
        "\nThat's what you ask us, that's what we know!\""

        "\n\"Pretty good, sure as you're born."
        "\nPretty good, sure as you're born.\""

        "\n\n\"How do you do?\""
        "\n(Hi there!)"
        "\n\"Fine, how are you?\""
        "\n(Howdy do?)"
        "\n\"How you come on?\""
        "\n(Nice seein' ya!)"
        "\n\"Pretty good, sure as you're born."
        "\nPretty good, sure as you're born."
        "\nPretty good, sure as you're born.\""
        
        "\n\nAfter passing the Fishing Place you meet Br'er Rabbit finally, he's got a bag packed and is ready to head out,"
        "\nthere is also Mr. Bluebird singing along with him."

        "\n\nBr'er Rabbit:"
        "\n\"I'm lookin' for a little more adventure.\""
        
        "\n\nMr. Bluebird:"
        "\n\"He's headin' for a little bit of fun now.\""
        
        "\n\nBr'er Rabbit:"
        "\n\"I'm hopin' for a little more excitement.\""
        
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Time to be movin' along!\""
        
        "\n\nBr'er Rabbit:"
        "\n\"I've had enough of this ol' briar patch.\""
            
        "\n\nMr. Bluebird:"
        "\n\"He thinks an adventure's about to hatch."
        "\nHe's movin' on,\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Say goodbye to me."
        "\nDown at the Laughin' Place is where I'll be!\""
            
        "\n\nMr. Bluebird:"
        "\n\"He's lookin' for a little more adventure.\""
            
        "\n\nBr'er Rabbit:"
        "\n\"I'm headin' for a little bit of fun now.\""
            
        "\n\nMr. Bluebird:"
        "\"I'm hopin' for a little more excitement,\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Time to be movin' along!\""
            
        "\n\nMr. Bluebird:"
        "\n\"Stop jumpin', Br'er Rabbit, you'll run out of breath!"
        "\nWhy don't you sit backand calm yourself?\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Well, the grasshopper jump, so do the flea."
        "\nI do what I likes, and I suits me."
        "\nI'm heading for-\""
            
        "\n\nMr. Bluebird:"
        "\n\"A little bit of fun now.\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Time to be movin' along!"
        "\nIt's time to be movin' along!\""
            
        "\n\nMr. Bluebird:"
        "\n\"The weather is good, and the fishin' is fine."
        "\nNow what'll you do with all of your time?\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Oh I zigs and I zags, I tos and I fros."
        "\nThat's what you asked me, and that's what you know!\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Time to be movin' along!"
        "\nTime to be movin' along!\""
            
        "\n\nStanding off to the right of Br'er Rabbit is Br'er Fox standing atop Br'er Bear's shoulders,"
        "\nthe two are plotting to capture Br'er Rabbit once and for all."
            
        "\n\nBr'er Fox:"
        "\n\"Now's our chance to set a trap for Br'er Rabbit.\""
        "\n(Br'er Bear Guffaws.)"
        "\n\"So Br'er Rabbit's looking for adventure, eh?\""
        "\n(Br'er Bear Guffaws.)"
        "\n\"I'm gonna catch that Br'er Rabbit this time, for sure!\""
        "\n(Br'er Bear Guffaws.)"
            
        "\n\nAfter passing by Br'er Rabbit and Mr. Bluebird your log comes up to Br'er Porcupine and a Young Rabbit."
        
        "\n\nBr'er Porcupine (singing):"
        "\n\"He's lookin' for a little more adventure,"
        "\nBut he's headin' for a little bit of trouble."
        "\nHe's headin' for a little bit of danger."
        "\nTime to be turnin' around!\""

        "\n\n\"Hey, Br'er Rabbit, better mend your ways."
        "\nYou're headed for trouble one of these days!"
        "\nWarnin' this rabbit, I'm afraid, is a waste,"
        "\nHe's makin' his way to the Laughing Place.\""

        "\n\n\"He's lookin' for a little more adventure,"
        "\nBut he's headin' for a little bit of trouble."
        "\nHe's headin' for a little bit of danger."
        "\nTime to be turnin' around!\""

        "\n\n\"Careful, Br'er Rabbit, better mend your ways."
        "\nYou're headed for trouble one of these days!"
        "\nWarnin' this rabbit, I'm afraid, is a waste,"
        "\nHe's makin' his way to the Laughing Place.\""

        "\n\n\"He's headin' for a little bit of danger."
        "\nTime to be turnin' around."
        "\nTime to be turnin' around.\""
            
        "\n\nYoung Rabbit:"
        "\n\"There goes that Br'er Rabbit, being chased by Br'er Fox and Br'er Bear."
            
        "\n\nThe log makes another turn and this time you see Br'er Bear stuck in a snare while Br'er Fox ridicules him,"
        "\nAcross the water from Br'er Bear and Br'er Fox you see that Br'er Rabbit it laughing at them."
            
        "\n\nBr'er Bear:"
        "\n\"Everybody's got a Laughing Place, a Laughing Place...\""
            
        "\n\nBr'er Fox:"
        "\n\"Look here, Brother Bear-this has gone far enough."
        "\nNow get down from that tree!"
        "\nWe gotta catch that rabbit what's makin' a fool outta you!\""
            
        "\n\nBr'er Bear:"
        "\n\"He is?\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Haha, you boys can't catch me!"
        "\nWhy, my Laughin' Place is where I'm bound!\""
            
        "\n\nBr'er Bear:"
        "\n\"Everybody got a Laughing Place, ho ho ho...\""
            
        "\n\nBr'er Fox:"
        "\n\"You sure done made a fool of yourself, Br'er Bear."
        "\nYou done sprung my Br'er Rabbit trap, and now he's laughin' at you!\""
            
        "\n\nBr'er Bear:"
        "\n\"He is?\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Br'er Fox! No need to get hung up over Br'er Bear!"
        "\nYou need a good dose of my Laughin' Place.\""
           
        "\n\nBr'er Roadrunner:"
        "\n\"Where is this secret Laughin' Place Br'er Rabbit's talkin' about?"
        "\nCan I go too?"
        "\nHey y'all-hold up there!"
        "\nI wants to see this here Laughin' Place old Br'er Rabbit's talkin' about.\""
            
        "\n\nYour log makes it into the laughing place to see Possums/Frogs/Turtles all singing about the laughing place:"
        "\n\"Everybody's got a Laughing Place,"
        "\nA Laughing Place to go-ho-ho."
        "\nTake your frown, turn it upside-down,"
        "\nAnd you'll find yours we know-ho-ho!\""

        "\n\n\"Honey and rainbows on our way."
        "\nWe laugh because our work is play."
        "\nBoy are we in luck!"
        "\nWe're visiting our Laughing Place,"
        "\nYuk yuk yuk yuk yuk!"
        "\nYuk yuk yuk!\""

        "\n\n\"Everybody's got a Laughing Place,"
        "\nA Laughing Place to go-ho-ho."
        "\nTake a smile there, for a while,"
        "\nAnd you'll find yours, we know-ho-ho!\""

        "\n\n\"Honey and rainbows on your way."
        "\nTake that frown, turn it upside-down"
        "\nAnd soon you'll find you're here to stay.\""

        "\n\n\"Everybody's got a Laughing Place,"
        "\nA Laughing Place to go - ho - ho."
        "\nCome on in, give us all a grin,"
        "\nAnd you'll find yours, I know-ho-ho!\""

        "\n\n\"Laughing is how we spend our day."
        "\nPlenty o' fun is what we make."
        "\nBoy are we in luck!"
        "\nWe're visiting our Laughing Place."
        "\nYuk yuk yuk yuk yuk!\""

        "\n\n\"Everybody's got a Laughing Place,"
        "\nA Laughing Place to go-ho-ho."
        "\nWe've found one that's filled with fun,"
        "\nAnd you'll find yours we know-ho-ho.\""

        "\n\n\"Everybody's got a Laughing Place,"
        "\nA Laughing Place to go-ho-ho!"
        "\nTake that frown, turn it upside down,"
        "\nAnd you'll find yours we say-hey-hey."
        "\nAnd soon you'll find you're here to stay!\""
            
        "\n\nBr'er Bear:"
        "\n\"What Laughin' Place? There's just bees in here.\""
            
        "\n\nBr'er Fox:"
        "\n\"Ow! Ow!\""
            
        "\n\n(Br'er Rabbit Squeals and laughs.)"
            
        "\n\nBr'er Fox:"
        "\n\"Ow! Ooh! Oh, oh, oh, ow!\""
            
        "\n\nBr'er Bear:"
        "\n\"I don't see no Laughin' Place. Just bees!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Hee, hahahaha!\""
            
        "\n\nYour log goes down a big hill with a sign pointing \"To the Laughin' Place.\""
        "\nAfter going down the drop bees buzz Everybody's Got a Laughing Place around your log."
            
        "\n\nBr'er Bear and Br'er Fox:"
        "\n\"Ow, ooh, ooh, oh, ow.\""
            
        "\n\nBr'er Rabbit:"
        "\n(Laughing)"
        "\n\"I do declare, Br'er Bear, my Laughin' Place sure gonna give you hives!"
        "\nHa! I didn't say this was your Laughin' Place, Br'er Bear-I said it was mine! And I'm laughin'!\""
            
        "\n\nThe music turns ominous as Br'er Fox has caught Br'er Rabbit."
            
        "\n\nBr'er Fox:"
        "\n\"I bet you wish you'd never been born, huh, Br'er Rabbit?"
        "\nWell, you're mine! You're mine!\""
        "\n(Br'er Fox Laughs)"
        "\n\"And you'll not be gettin' away this time!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Ohhh, what are you doin', Br'er Fox? Let me go!!\""
            
        "\n\nBr'er Fox:"
        "\n\"Say, Br'er Rabbit, how 'bout I take you to my Laughin' Place?\""
        "\n(Br'er Fox Laughs)"
        "\n\"'Cept I don't expect you'll be doin' much laughin'!\""
        "\n(Br'er Fox Laughs)"
            
        "\n\nBr'er Rabbit:"
        "\n\"Ohh, where you takin' me, Br'er Fox? Let me go!\""
            
        "\n\nYour boat makes a right turn to a large lifthill that is completely pitch black,"
        "\nthe only source of light being the sunlight from the very topside of the lifthill,"
        "\nmeanwhile two Vultures stand overhead."
            
        "\n\nVulture #1:"
        "\n\"Everybody's got a Laughing Place.\""
            
        "\n\nVulture #2:"
        "\n\"Maybe this one is yours...\""
            
        "\n\nVulture #1:"
        "\n\"And wait till you see that old Br'er Rabbit!\""
            
        "\n\nVulture #2:"
        "\n\"He sure ain't laughin' no more!\""
            
        "\n\nVulture #1:"
        "\n\"If you finally found your Laughing Place...\""
            
        "\n\nVulture #2:"
        "\n\"How come you aren't laughing?\""
            
        "\n\nVulture #1:"
        "\n\"That Br'er Rabbit, he learned his lesson all right.\""
            
        "\n\nVulture #2:"
        "\n\"But I'm afraid he learned it too late!\""
            
        "\n\nVulture #1:"
        "\n\"Laughing Place?\""
        
        "\n\nVulture #2:"
        "\n\"We've got your Laughing Place."
        "\nRight up here.\""
            
        "\n\nVulture #1:"
        "\n\"So, you're looking for a Laughing Place, eh?\""
            
        "\n\nVulture #2:"
        "\n\"We'll show you a Laughing Place!\""
            
        "\n\nVulture #1:"
        "\n\"Time to be turnin' around.\""
            
        "\n\nVulture #2:"
        "\n\"If only you could!\""
            
        "\n\nNearing the top of the lift hill Br'er Rabbit can be seen tied up to a stick near the wall of a cave,"
        "\nthe shadow of Br'er Fox on the wall with a cauldron sitting in the center of the cave."
            
        "\n\nBr'er Fox:"
        "\n\"Well, Br'er Rabbit, I expect I'll just have to skin ya!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Go ahead, Br'er Fox, skin me if you like."
        "\nBut please don't fling me in that briar patch!\""
            
        "\n\nBr'er Fox:"
        "\n\"Well, now, Br'er Rabbit, maybe I'll just have to roast ya!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Yessir, Br'er Fox."
        "\nBut whatever you do, please don't fling me in that briar patch!\""
            
        "\n\nBr'er Fox:"
        "\n\"You know, Br'er Rabbit, I think I'll have to hang ya!\""
            
        "\n\nBr Rabbit:"
        "\n\"That's all right, Br'er Fox-hang me if you gotta!"
        "\nBut please, please don't fling me in that briar patch!\""
            
        "\n\nBr'er Bear:"
        "\n\"Briar patch?"
        "\nBriar patch!\""
            
        "\n\nYour log goes down the large 52ft drop, getting you soaked in the process."
        "\nThe music changes to \"Zip-a-Dee-Doo-Dah.\""
        "\nThe log goes around a small bend and down a very very small drop leading to a cave opening."
        "\nAs your log rounds the corner of the cave opening theres a large banner overhead that reads \"Welcome Home Br'er Rabbit!\""
        "\nOn your left a crocodile trio sit playing instruments,"
        "\nwhile a boat full of an assortment of animals sing:"
            
        "\n\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nMy oh my, what a wonderful day!"
        "\nWelcoming back Br'er Rabbit today."
        "\nWe always knew that he'd get away!\""

        "\n\n\"He's had enough of movin' on now."
        "\nIt's where he's bornand bred in."
        "\nThe briar patch is where he's headin'!"
        "\nZip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nWonderful feeling, wonderful day!\""

        "\n\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nMy oh my, what a wonderful day!"
        "\nPlenty of sunshine heading our way."
        "\nWe never doubted he'd get away!\""

        "\n\n\"Moving on taught him a lesson."
        "\nYou've learned it well, Br'er Rabbit."
        "\nGettin' caught's a nasty habit."
        "\nZip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nWonderful feeling, feeling this way!\""

        "\n\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nBr'er Fox and Br'er Bear are gonna get it today."
        "\nZip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nThat hungry gator's gettin' his way!\""

        "\n\n\"Mr.Bluebird on my shoulder."
        "\nIt's the truth, it's actual."
        "\nEverything is satisfactual.\""
 
        "\n\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nWonderful feelling, wonderful day!\""

        "\n\nNext up you see Br'er Bear stuck in the briar patch, while Br'er Fox gets his tail chomped on by a crocodile."
           
        "\n\nBr'er Fox:"
        "\n\"This is all your fault, Br'er Bear."
        "\nSo stop that singing! Ow! Ow!\""
            
        "\n\nBr'er Bear:"
        "\n\"My oh my, what a wonderful... Zip-a-dee-doo-dah...\""
            
        "\n\nBr'er Fox:"
        "\n\"Br'er Bear, this is your fault! You flung us into this here predicament."
        "\nNow stop that singing! Ow! Ow!\""
            
        "\n\nYou pass by the Br'ers, you see Br'er Rabbit lounging back with Mr. Bluebird"
            
        "\n\nBr'er Rabbit:"
        "\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nHome sweet home is the lesson today."
        "\nMy, oh my! Born and bred in the briar patch, and I'm here to stay!\""

        "\n\n\"Oh, I'm thru with moving on now."
        "\nIt's where I'm bornand bred in."
        "\nBriar patch is where I'm headin'!\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"I'm back in my home now, and I'm sure gonna stay!\""
            
        "\n\nMr. Bluebird:"
        "\n\"I told you, Br'er Rabbit! There ain't no place further from trouble.\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Home sweet home is the lesson today.\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Don't you worry, Mr.Bluebird! I learned my lesson.\""
            
        "\n\nMr. Bluebird:"
        "\n\"The briar patch is where you were born, and the briar patch is where you're gonna stay.\""
            
        "\n\nBr'er Rabbit:"
        "\n\"One of these days, I gotta thank Br'er Fox and Br'er Bear for flingin' me back home to my briar patch.\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"I'm back in my home now, and I'm gonna stay."
        "\nMy, oh my! Born and bred in the briar patch, and I'm here to stay!\""
        
        "\n\nMr. Bluebird:"
        "\n\"I'm glad you made it home safe and sound this time, Br'er Rabbit!\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"I'm sure glad to be here...\""
            
        "\n\nMr. Bluebird:"
        "\n\"And he's here to stay!\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Zip-a-dee-doo-dah, zip-a-dee-ay!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Home sweet home-\""
            
        "\n\nMr. Bluebird:"
        "\n\"Is the lesson today.\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Don't you worry, Mr.Bluebird! I learned my lesson.\""
            
        "\n\nMr. Bluebird:"
        "\n\"I'm glad you made it home safe and sound this time, Br'er Rabbit.\""
            
        "\n\nBr'er Rabbit:"
        "\n\"Mr.Bluebird on my shoulder,"
        "\nIt's the truth!\""
            
        "\n\nMr. Bluebird:"
        "\n\"It's the truth!\""
            
        "\n\nBr'er Rabbit:"
        "\n\"It's actual!\""
            
        "\n\nMr. Bluebird:"
        "\n\"It's actual!\""
            
        "\n\nBr'er Rabbit and Mr. Bluebird:"
        "\n\"Everything is satisfactual!"
        "\nZip-a-dee-doo-dah, zip-a-dee-ay!"
        "\nWonderful feelin', wonderful day.\""
            
        "\n\nYour log reaches the station and your group all unloads."
        "\nYou had a zip-a-dee-doo-dah time on Splash Mountain and are now back in Frontierland.", true);
    #pragma endregion SPLASH MOUNTAIN

    #pragma region BIG THUNDER MOUNTAIN
    Location* bigThunderMountain = new Location("Big Thunder Mountain", 
        "\"Howdy partners!"
        "\nFor your safety, remain seated with your hands, arms, feet, and legs inside the train-and be sure to watch your kids."
        "\nIf any of you folks are wearin' hats or glasses, best remove 'em-'cause this here's the wildest ride in the wilderness!\""
        
        "\n\nA train enters the station filled with guests, as they exit the train you enter and sit comfortably,"
        "\na cast member checks your safety bar and makes sure its secured."
        
        "\n\nThe train begins to move forwards and proceeds into an opened cavern and up a lift hill,"
        "\nstalagmites and stalagtites to the right with a rich orange illuminating them all."
        "\nThe train reaches the top of the lift hill and goes down a series of twists and turns that throw you around in your seat,"
        "\nas well as multiple lift hills and across a water section that wobbles the train back and forth, ragdolling you around."
        "\nThe ride lasts a mere 3 minutes, which is actually quite a long time for a rollercoaster."
        "\nThe train reaches the station and you exit the train back to Frontierland exhilarated.", true);
    #pragma endregion BIG THUNDER MOUNTAIN

    Location* libertySquare = new Location("Liberty Square", 
        "Themed after colonial America, this land does not hold much in terms of rides,"
        "\nbut it does have the Haunted Mansion which is considered one of Disney's best and most clever rides ever made.");

    #pragma region HAUNTED MANSION
    // The Haunted Mansion REALLY doesn't have the same effect as it does IRL, there's a ton of illusions and effects that you are missing out on
    Location* hauntedMansion = new Location("Haunted Mansion", 
        "Inside the Haunted Mansion you are directed in front of a fireplace that holds a picture of a man,"
        "\non both sides of the fireplace are double doors, what awaits you inside?"
        
        "\n\nYou hear the voice of a man begin to speak:"
        "\n\"When hinges creak in doorless chambers, and strange and frightening sounds echo through the halls."
        "\nWhenever candlelights flicker where the air is deathly still - that is the time when ghosts are present,"
        "\npracticing their terror with ghoulish delight!\""
        
        "\n\nThe door located on the left side of the fireplace opens as the man in the picture changes to that of a ghost!"
        
        "\n\nAs your group begins to head inside the doors and you hear the voice speak again:"
        "\n\"Welcome, foolish mortals, to the Haunted Mansion."
        "\nI am your host, your ghost host."
        "\nOur tour begins here in this gallery."
        "\nHere, where you see paintings of some of our guests as they appeared in their corruptible, mortal state."
        "\nKindly step all the way in please, and make room for everyone."
        "\nThere's no turning back now.\""
        
        "\nA cast member speaks from the door your group entered from:"
        "\"Please drag your bodies away from the walls and into the dead center of the room.\""
        
        "\n\nThe door you entered from has now closed leaving the walls of the room completely pitch black,"
        "\nthe room seems to be designed as an octagon and above you can 4 paintings consisting of 2 woman and 2 men."
        
        "\n\nGhost Host:"
        "\n\"Your cadaverous pallor betrays an aura of foreboding, almost as though you sense a disquieting metamorphosis."
        "\nIs this haunted room actually stretching? Or is it your imagination - hmm?"
        "\nAnd consider this dismaying observation: this chamber has no windows and no doors..."
        "\nwhich offers you this chilling challenge: to find a way out!"
        "\nHAHAHAHAHAHAHAHA"
        "\nOf course, there's always my way.\""
        
        "\n\nAs the Ghost Host says this Thunder claps and the lights go out, above you see what appears to be a hanging body"
        "\nyou hear a scream as the lights go out again to the sounds of bones hitting the ground"
        
        "\n\nGhost Host:"
        "\n\"Oh, I didn't mean to frighten you prematurely. The real chills come later. "
        "\nNow, as they say, \"look alive,\" and we'll continue our little tour."
        "\nAnd let's all stay together, please.\""
        
        "\n\nAnother set of doors opens leading to a hallway as the Ghost Host follows you:"
        "\n\"And now, a carriage approaches to carry you into the boundless realm of the supernatural."
        "\nOnce on board, remain safely seated with your hands, arms, feet, and legs inside. And watch your children, please.\""
        
        "\n\nSafely on board of your \"Doom Buggie\" the Ghost Hosts voice plays seemingly from behind your head:"
        "\n\"Do not pull down on the safety bar, please. I will lower it for you. "
        "\nAnd heed this warning: the spirits will materialize only if you remain quietly seated at all times."
        "\nOh yes, and no flash pictures, please. We spirits are frightfully sensitive to bright lights.\""
        
        "\n\nYour Doom Buggie passes into a Library, the statue's heads seems to follow you as you pass by."
        
        "\n\nGhost Host:"
        "\n\"Our library is well-stocked with priceless first editions - only ghost stories, of course"
        "\nand marble busts of the greatest ghost writers the literary world has ever known."
        "\nThey have all retired here, to the Haunted Mansion."
        "\nActually, we have 999 happy haunts here. But there's room for 1,000."
        "\nAny volunteers? hmm?"
        
        "\n\nAs your Doom Buggie nears an Escher Staircase the Ghost Host continues:"
        "\n\"If you should decide to join us, final arrangements may be made at the end of the tour.\""
        
        "\n\nYour Doom Buggie finds itself in a corridor full of doors as the Ghost Host speaks still:"
        "\n\"We find it delightfully unlivable here in this ghostly retreat."
        "\nEvery room has wall-to-wall creeps, and hot and cold running chills. "
        "\nShhh, listen!"
        
        "\n\nAs the Ghost Host says this your Buggie nears a coffin whose resident is trying to break out"
        
        "\n\nMan In Coffin:"
        "\n\"Let me out, let me out of here!\""
        
        "\n\nYour Doom Buggie continues down the hall as Door knockers clang, and one door is actually warping!"
        "\nThe Doom Buggie passes a grandfather clock whose arms are moving much too fast and you enter another room."
        "\nThis room it mostly pitch black, but has instruments and such floating around the edges,"
        "\nand a floating glass ball that has a head speaking from inside it:"
        
        "\n\n\"Serpents and spiders, tail of a rat, call in the spirits, wherever they're at!\""
        "\n(Sounds of ghosts.)"
        "\n\"Rap on a table - it's time to respond. Send us a message from somewhere beyond...\""
        "\n(Knock on table.)"
        "\n\"Goblins and ghoulies from last Halloween, awaken the spirits with your tambourine!\""
        "\n(Sound of a tambourine.)"
        "\n\"Creepies and crawlies, toads in a pond, let there be music from regions beyond!\""
        "\n(A brass instrument plays part of \"Grim Grinning Ghosts.\")"
        "\n\"Wizards and witches, wherever you dwell, give us a hint, by ringing a bell!\""
        "\n(A bell rings.)"
        
        "\n\nYour Doom Buggie exits Madame Leota's Room to find a ballroom completely filled with Ghosts!"
        "\nThe Ghost Host speaks:"
        "\n\"The happy haunts have received your sympathetic vibrations and are beginning to materialize."
        "\nThey're assembling for a swinging wake, and they'll be expecting me... I'll see you all a little later.\""
        
        "\n\nGhosts fly around the table in the center of the room as five ghosts blip in and out of existance."
        "\nTo the left are groups of ghosts dancing along to a Ghost playing Organ Music left of them."
        "\nAbove, there are paintings askew, among them are two paintings of men holding firearms,"
        "\ntwo ghosts come out of them and fire a shot at eachother then blip back into the paintings."
        
        "\n\nThe next room you enter is the Attic which is filled with pictures of a woman with many different men,"
        "\nin the corner of the room you see the Ghost Bride herself as she speaks:"
        
        "\n\nIn sickness and in... wealth."
        "\n(an axe apears in her hands)"
        "\nYou may now kiss the bride."
        "\n(an axe apears in her hands)"
        "\nWe'll live happily ever after."
        "\n(an axe apears in her hands)"
        "\nTill death do us part."
        "\n(an axe apears in her hands)"
        "\nHere comes the bride."
        "\n(an axe apears in her hands)"
        "\nAs long as we both shall live."
        "\n(an axe apears in her hands)"
        "\nFor better or for... worse."
        "\n(an axe apears in her hands)"
        "\nI do. I did."
        "\n(an axe apears in her hands)"

        "\n\nYour Doom Buggie moves out of Attic window and into a Graveyard."
        
        "\n\nSeveral Ghosts (sung):"
        "\n\"When the crypt doors creak and the tombstones quake,"
        "\nSpooks come out for a swinging wake."
        "\nHappy haunts materializeand begin to vocalize."
        "\nGrim grinning ghosts come out to socialize!\""

        "\n\n\"Now, don't close your eyesand don't try to hide,"
        "\nFor a silly spook may sit by your side."
        "\nShrouded in a daft disguise, they pretend to terrorize."
        "\nGrim grinning ghosts come out to socialize!\""

        "\n\n\"As the moon climbs high o'er the dead oak tree,"
        "\nSpooks arrive for the midnight spree."
        "\nCreepy creeps with eerie eyes start to shriekand harmonize."
        "\nGrim grinning ghosts come out to socialize!\""

        "\n\n\"When you hear the knell of a requiem bell,"
        "\nWeird glows gleam where spirits dwell."
        "\nRestless bones etherealize, rise as spooks of every size!\""
        
        "\n\nThe Ghost Host Speaks after being silent for a while:"
        "\n\"Ah, there you are!"
        "\nAnd just in time... there's a little matter I forgot to mention"
        "\nbeware of hitchhiking ghosts!"
        "\nThey have selected you to fill our quota, and they'll haunt you until you return!\""
        
        "\n\nAs your Buggie turns a corner you see Ghosts Looking to hitch hike!"
        "\nWhen the Buggie turns you can see a mirror of yourself with a ghost sitting atop your Buggie."
        "\nYour Buggie passes the mirror to a large doorway with a little Leota standing on the top ledge"
        
        "\n\nLittle Leota:"
        "\n\"Hurry back! Hurry back!"
        "\nBe sure to bring your death certificate... if you decide to join us."
        "\nMake final arrangements now! "
        "\nWe've been dying to have you...\""
            
        "\n\nGhost Host as you near the exit:"
        "\n\"Now I will raise the safety bar, and a ghost will follow you home!"
        "\nHAHAHAHAHAHAH\""
            
        "\n\nThe safety bar lifts and you exit the ride back to Liberty Square", true);
    #pragma endregion HAUNTED MANSION

    Location* fantasyland = new Location("Fantasyland", 
        "Located just behind the castle and flowering out to the sides,"
        "\nthis beautiful land is themed after Disney's animated fairy tale films,"
        "\nFantasy, as well as the towns and villages of Europe."
        "\nThis land is surely a must see for those looking to fill their fairy tale cravings with classic rides such as:"
        "\nthe originally designed by Walt Disney himself, \"Its A Small World.\""
        "\nor soar the skies alongside Peter Pan himself on \"Peter Pan's Flight.\""
        "\nOr maybe you are looking for something newer with more thrill to it,"
        "\nenjoy a ride on the 7 Dwarfs Mine Train and see the dwarfs themselves alongside the classic song \"Heigh-Ho.\""
        "\nPerhaps you are looking for something more... wet,"
        "\nexperience Ariel's adventure in \"Under The Sea ~ Journey of the Little Mermaid.\"");

    #pragma region SMALL WORLD
    Location* smallWorld = new Location("It's A Small World", 
        "", true);
    #pragma endregion SMALL WORLD

    Location* peterPan = new Location("Peter Pan's Flight", "", true);
    Location* carrousel = new Location("Prince Charming Regal Carrousel", "", true);
    Location* mineTrain = new Location("7 Dwarfs Mine Train", "", true);
    Location* underTheSea = new Location("Under The Sea ~ Journey of The Little Mermaid", "", true);
    Location* madTeaParty = new Location("Mad Tea Party", "", true);

    Location* storybookCircus = new Location("Storybook Circus", "");
    Location* barnstormer = new Location("Goofy's Barnstormer", "", true);
    Location* dumbo = new Location("Dumbo the Flying Elephant", "", true);

    Location* tomorrowland = new Location("Tomorrowland", "");
    Location* spaceMountain = new Location("Space Mountain", "", true);
    Location* peopleMover = new Location("PeopleMover", "", true);
    Location* laughFloor = new Location("Monsters, Inc. Laugh Floor", "", true);
    Location* astroOrbiter = new Location("Astro Orbiter", "", true);
    Location* autopia = new Location("Autopia - The Tomorrowland Speedway", "", true);

    // Epcot
    Location* futureWorld = new Location("Future World", "");
    Location* spaceshipEarth = new Location("Spaceship Earth", "", true);
    Location* theSeas = new Location("The Seas with Nemo & Friends", "", true);
    Location* theLand = new Location("Living with the Land", "",true);
    Location* soarin = new Location("Soarin' Around the World", "", true);
    Location* figment = new Location("Journey Into Imagination With Figment", "", true);
    Location* missionSpace = new Location("Mission: SPACE", "", true);
    Location* testTrack = new Location("Test Track", "", true);

    Location* worldShowcase = new Location("World Showcase", "");
    Location* granFiestaTour = new Location("Gran Fiesta Tour Starring The Three Caballeros", "", true);
    Location* frozen = new Location("Frozen Ever After", "", true);

    // Hollywood Studios
    Location* hollywoodBoulevard = new Location("Hollywood Boulevard", "");
    Location* echoLake = new Location("Echo Lake", "");
    Location* pixarPlace = new Location("Pixar Place", "");

    Location* grandAvenue = new Location("Grand Avenue", "");
    Location* muppetVision = new Location("Muppet*Vision 3D", "", true);

    Location* galaxysEdge = new Location("Star Wars: Galaxy's Edge", "");
    Location* smugglersRun = new Location("Millennium Falcon: Smugglers Run", "", true);
    Location* resistance = new Location("Rise of the Resistance", "", true);

    Location* commissaryLane = new Location("Commissary Lane", "");
    Location* starTours = new Location("Star Tours - The Adventures Continue", "", true);

    Location* sunsetBoulevard = new Location("Sunset Boulevard", "");
    Location* towerOfTerror = new Location("Tower Of Terror", "", true);
    Location* rockNRollercoaster = new Location("Rock 'n' Roller Coaster Starring Aerosmith", "", true);

    Location* animationCourtyard = new Location("Animation Courtyard", "");
    Location* runawayRailroad = new Location("Mickey & Minnie's Runaway Railroad", "", true);

    Location* toyStoryLand = new Location("Toy Story Land", "");
    Location* toyStoryMania = new Location("Toy Story Mania!", "", true);
    Location* slinky = new Location("Slinky Dog Dash", "", true);
    Location* saucers = new Location("Alien Swirling Saucers", "", true);

    // Animal Kingdom
    Location* oasis = new Location("Oasis", "");
    Location* discoveryIsland = new Location("Discovery Island", "");
    
    Location* pandora = new Location("Pandora - The World of Avatar", "");
    Location* flightOfPassage = new Location("Avatar Flight of Passage", "", true);
    Location* riverJourney = new Location("Na'vi River Journey", "", true);

    Location* africa = new Location("Africa", "");
    Location* safaris = new Location("Kilimanjaro Safaris", "", true);

    Location* asia = new Location("Asia", "");
    Location* everest = new Location("Expedition Everest - Legend of the Forbidden mountain", "", true);
    Location* kaliRiverRapids = new Location("Kali River Rapids", "", true);

    Location* dinoland = new Location("DinoLand U.S.A.", "");
    Location* dinosaur = new Location("DINOSAUR", "", true);
    Location* triceratopSpin = new Location("TriceraTop Spin", "", true);
    Location* primevalWhirl = new Location("Primeval Whirl", "", true);


    // all the exits that each location has access to
    hub->AddArea(magicKingdomEntrance);
    hub->AddArea(epcotEntrance);
    hub->AddArea(hollywoodStudiosEntrance);
    hub->AddArea(animalKingdomEntrance);

    // Magic Kingdom Exits
    magicKingdomEntrance->AddArea(hub);
    magicKingdomEntrance->AddArea(mainStreetUSA);

    mainStreetUSA->AddArea(magicKingdomEntrance);
    mainStreetUSA->AddArea(castle);
    mainStreetUSA->AddArea(emporium);
    mainStreetUSA->AddArea(railroad);

    railroad->AddStation(mainStreetUSA, 
        "\"Welcome aboard the Walt Disney World Railroad!"
        "\nWe're about to take a grand circle tour of the Magic Kingdom, with stops along the way at Frontierland and Fantasyland."
        "\nJust sit tight and keep your hands, arms, feet, and legs well inside the train."
        "\nWe're leaving Main Street Station right now, so wave goodbye"
        "\nbut if you stay on board long enough, why, sooner or later, you'll be back.\"", 
        
        "\"We've made a complete trip around the Magic Kingdom."
        "\nFor those of you who've been on board for the whole journey, thanks for puttin' up with me these last few days." 
        "\nIf you're stayin' with us, we'll be headed for Frontierland next."
        "\nRight now, please stay seated until our train comes to a complete stop."
        "\nThen pick up your belongings, and carefully step off the train."
        "\nIf you have strollers to unfold,"
        "\nplease take 'em all the way beyond the platform so we can safely board passengers for the next leg of our journey."
        "\nThis is Main Street Station - Main Street, U.S.A.\"");

    railroad->AddStation(frontierland,
        "\"Howdy, folks! If you're just joinin' us, welcome aboard the Walt Disney World Railroad. "
        "\nWe're headed for Fantasyland and to Main Street, U.S.A."
        "\nEverybody stay seated, and keep your hands and arms, feet, and legs safely inside the train."
        "\nAnd as always, keep an eye on your little ones.\"", 
        
        "\"We've reached the wild west of the Magic Kingdom: Frontierland."
        "\nWell, this outpost is home to the covered wagons, cowpokes, and Country Bears."
        "\nAnd we've got our own mountain range of excitin' adventures. "
        "\nYou might catch a runaway mine train at Big Thunder Mountain,"
        "\nor hop on over to Splash Mountain and join Br'er Rabbit for a 50-foot drop straight down into the briar patch. "
        "\nWe've reached Frontierland Station, everyone, so sit tight until we've come to a complete stop. "
        "\nIf you're disembarking here, please carry your strollers all the way off the platform before you unfold 'em."
        "\nThat'll help make room for the new passengers joinin' us. Watch your step now - this is Frontierland Station.\"");

    railroad->AddStation(storybookCircus, 
        "\"Looks like we're ready to embark on the next leg of our journey!"
        "\nOur destination is Main Street, U.S.A."
        "\nNow, everyone stay seated, and keep your hands and arms, feet, and legs inside the train at all times. "
        "\nAnd please, keep an eye on your children.\"", 
        
        "\"If you've been riding trains as long as this old-timer, "
        "\nyou may remember the days when the circus would come to town on the local railway."
        "\nWell, the circus is here, and it's set up permanent headquarters as the Fantasyland Storybook Circus."
        "\nThis is the place to fly high with Dumbo, "
        "\nor join Goofy on the Barnstormer - a frolicking ride of circus acrobatics and coaster thrills."
        "\nThis station is also your gateway to the rest of Fantasyland and Tomorrowland."
        "\nNow, please wait until the train has come to a complete stop, "
        "\ngather your belongings, and carry your strollers away from the platform before you start unfoldin' 'em."
        "\nThat way, we can start loadin' up for the next leg of our trip."
        "\nFor those of your disembarking, please watch your step, "
        "\nand thanks for traveling with us on the Walt Disney World Railroad."
        "\nJoin us again real soon. If you're stayin' aboard, our next stop is Main Street Station.\"");

    emporium->AddArea(mainStreetUSA);
    emporium->AddArea(castle);

    castle->AddArea(mainStreetUSA);
    castle->AddArea(adventureland);
    castle->AddArea(libertySquare);
    castle->AddArea(fantasyland);
    castle->AddArea(tomorrowland);

    adventureland->AddArea(castle);
    adventureland->AddArea(frontierland);
    adventureland->AddArea(libertySquare);
    adventureland->AddRide(jungleCruise);
    adventureland->AddRide(piratesOfTheCaribbean);
    adventureland->AddRide(tikiroom);
    adventureland->AddRide(carpets);

    frontierland->AddArea(adventureland);
    frontierland->AddArea(libertySquare);
    frontierland->AddArea(railroad);
    frontierland->AddRide(splashMountain);
    frontierland->AddRide(bigThunderMountain);
    
    libertySquare->AddArea(castle);
    libertySquare->AddArea(frontierland);
    libertySquare->AddArea(fantasyland);
    libertySquare->AddRide(hauntedMansion);

    fantasyland->AddArea(castle);
    fantasyland->AddArea(libertySquare);
    fantasyland->AddArea(storybookCircus);
    fantasyland->AddArea(tomorrowland);
    fantasyland->AddRide(smallWorld);
    fantasyland->AddRide(peterPan);
    fantasyland->AddRide(carrousel);
    fantasyland->AddRide(mineTrain);
    fantasyland->AddRide(underTheSea);
    fantasyland->AddRide(madTeaParty);

    storybookCircus->AddArea(fantasyland);
    storybookCircus->AddArea(railroad);
    storybookCircus->AddRide(dumbo);
    storybookCircus->AddRide(barnstormer);
    
    tomorrowland->AddArea(castle);
    tomorrowland->AddArea(fantasyland);
    tomorrowland->AddRide(spaceMountain);
    tomorrowland->AddRide(peopleMover);
    tomorrowland->AddRide(laughFloor);
    tomorrowland->AddRide(astroOrbiter);
    tomorrowland->AddRide(autopia);

    // Epcot Exits
    epcotEntrance->AddArea(hub);
    epcotEntrance->AddArea(futureWorld);

    futureWorld->AddArea(epcotEntrance);
    futureWorld->AddArea(worldShowcase);
    futureWorld->AddRide(spaceshipEarth);
    futureWorld->AddRide(theSeas);
    futureWorld->AddRide(theLand);
    futureWorld->AddRide(soarin);
    futureWorld->AddRide(figment);
    futureWorld->AddRide(missionSpace);
    futureWorld->AddRide(testTrack);

    worldShowcase->AddArea(futureWorld);
    worldShowcase->AddRide(granFiestaTour);
    worldShowcase->AddRide(frozen);

    // Hollywood Studios Exits
    hollywoodStudiosEntrance->AddArea(hub);
    hollywoodStudiosEntrance->AddArea(hollywoodBoulevard);

    hollywoodBoulevard->AddArea(hollywoodStudiosEntrance);
    hollywoodBoulevard->AddArea(sunsetBoulevard);
    hollywoodBoulevard->AddArea(echoLake);
    hollywoodBoulevard->AddArea(animationCourtyard);

    animationCourtyard->AddArea(hollywoodBoulevard);
    animationCourtyard->AddArea(echoLake);
    animationCourtyard->AddArea(commissaryLane);
    animationCourtyard->AddArea(pixarPlace);
    animationCourtyard->AddRide(runawayRailroad);

    pixarPlace->AddArea(animationCourtyard);
    pixarPlace->AddArea(toyStoryLand);

    toyStoryLand->AddArea(pixarPlace);
    toyStoryLand->AddArea(galaxysEdge);
    toyStoryLand->AddRide(toyStoryMania);
    toyStoryLand->AddRide(slinky);
    toyStoryLand->AddRide(saucers);

    sunsetBoulevard->AddArea(hollywoodBoulevard);
    sunsetBoulevard->AddRide(towerOfTerror);
    sunsetBoulevard->AddRide(rockNRollercoaster);

    echoLake->AddArea(hollywoodBoulevard);
    echoLake->AddArea(animationCourtyard);
    echoLake->AddArea(commissaryLane);

    commissaryLane->AddArea(echoLake);
    commissaryLane->AddArea(animationCourtyard);
    commissaryLane->AddArea(grandAvenue);
    commissaryLane->AddRide(starTours);

    grandAvenue->AddArea(commissaryLane);
    grandAvenue->AddArea(galaxysEdge);
    grandAvenue->AddRide(muppetVision);

    galaxysEdge->AddArea(grandAvenue);
    galaxysEdge->AddArea(toyStoryLand);
    galaxysEdge->AddRide(smugglersRun);
    galaxysEdge->AddRide(resistance);

    // Animal Kingdom Exits
    animalKingdomEntrance->AddArea(hub);
    animalKingdomEntrance->AddArea(oasis);

    oasis->AddArea(animalKingdomEntrance);
    oasis->AddArea(discoveryIsland);

    discoveryIsland->AddArea(oasis);
    discoveryIsland->AddArea(pandora);
    discoveryIsland->AddArea(africa);
    discoveryIsland->AddArea(asia);
    discoveryIsland->AddArea(dinoland);

    pandora->AddArea(discoveryIsland);
    pandora->AddArea(africa);
    pandora->AddRide(flightOfPassage);
    pandora->AddRide(riverJourney);

    africa->AddArea(discoveryIsland);
    africa->AddArea(asia);
    africa->AddArea(pandora);
    africa->AddRide(safaris);

    asia->AddArea(discoveryIsland);
    asia->AddArea(dinoland);
    asia->AddArea(africa);
    asia->AddRide(everest);
    asia->AddRide(kaliRiverRapids);

    dinoland->AddArea(discoveryIsland);
    dinoland->AddArea(asia);
    dinoland->AddRide(dinosaur);
    dinoland->AddRide(triceratopSpin);
    dinoland->AddRide(primevalWhirl);

    // Ride Reactions
    
    // Adventureland
    jungleCruise->AddReaction("Laugh");

    piratesOfTheCaribbean->AddReaction("Amazement");
    piratesOfTheCaribbean->AddReaction("Wonder");

    tikiroom->AddReaction("Sing Along");
    tikiroom->AddReaction("Dance Along");

    carpets->AddReaction("Whirl");

    // Frontierland
    splashMountain->AddReaction("Raise Your Arms");
    splashMountain->AddReaction("Sing Along");

    bigThunderMountain->AddReaction("Ragdoll");
    bigThunderMountain->AddReaction("Hold Tight");

    // Liberty Square
    hauntedMansion->AddReaction("Spooked");

    // Fantasyland
    smallWorld->AddReaction("Spooked");
    smallWorld->AddReaction("Sing Along");

    peterPan->AddReaction("Amazement");
    peterPan->AddReaction("Wonder");

    carrousel->AddReaction("Whirl");

    mineTrain->AddReaction("Sing Along");
    mineTrain->AddReaction("Raise Your Arms");

    underTheSea->AddReaction("Amazement");
    underTheSea->AddReaction("Sing Along");

    madTeaParty->AddReaction("Dizzy");
    madTeaParty->AddReaction("Whirl");

    // Storybook Circus
    dumbo->AddReaction("Whirl");
    dumbo->AddReaction("Joy");
    
    barnstormer->AddReaction("Raise Your Arms");
    barnstormer->AddReaction("Joy");

    // Tomorrowland
    spaceMountain->AddReaction("Hold Tight");
    spaceMountain->AddReaction("Scream");

    peopleMover->AddReaction("Amazement");
    peopleMover->AddReaction("Wonder");

    laughFloor->AddReaction("Laugh");
    laughFloor->AddReaction("Relax");

    astroOrbiter->AddReaction("Zoom");
    astroOrbiter->AddReaction("Whirl");
    astroOrbiter->AddReaction("Joy");

    autopia->AddReaction("Wonder");
    autopia->AddReaction("Relax");

    // Future World
    spaceshipEarth->AddReaction("Wonder");
    spaceshipEarth->AddReaction("Amazement");
    spaceshipEarth->AddReaction("Relax");

    theSeas->AddReaction("Joy");
    theSeas->AddReaction("Wonder");

    theLand->AddReaction("Relax");
    theLand->AddReaction("Learn");

    soarin->AddReaction("Wonder");
    soarin->AddReaction("Amazement");
    soarin->AddReaction("Scream");
    soarin->AddReaction("Joy");

    figment->AddReaction("Laugh");
    figment->AddReaction("Sing Along");
    figment->AddReaction("Recoil");

    missionSpace->AddReaction("Dizzy");
    missionSpace->AddReaction("Hold Tight");
    missionSpace->AddReaction("Amazement");
    missionSpace->AddReaction("Scream");

    testTrack->AddReaction("Wonder");
    testTrack->AddReaction("Raise Your Arms");
    testTrack->AddReaction("Hold Tight");

    // World Showcase
    granFiestaTour->AddReaction("Dance Along");

    frozen->AddReaction("Sing Along");
    frozen->AddReaction("Dance Along");

    // Animation Courtyard
    runawayRailroad->AddReaction("Relax");
    runawayRailroad->AddReaction("Wonder");
    runawayRailroad->AddReaction("Amazement");

    // Toy Story Land
    toyStoryMania->AddReaction("Blast");
    toyStoryMania->AddReaction("Focus");

    slinky->AddReaction("Raise Your Arms");
    slinky->AddReaction("Zoom");
    slinky->AddReaction("Wooo");

    saucers->AddReaction("Dizzy");
    saucers->AddReaction("Hold Tight");
    saucers->AddReaction("Spin");

    // Sunset Boulevard
    towerOfTerror->AddReaction("Scream");
    towerOfTerror->AddReaction("Raise Your Arms");
    towerOfTerror->AddReaction("Hold Tight");

    rockNRollercoaster->AddReaction("Scream");
    rockNRollercoaster->AddReaction("Hold Tight");
    rockNRollercoaster->AddReaction("Holy Shit");

    // Commissary Lane
    starTours->AddReaction("Wonder");
    starTours->AddReaction("Amazement");
    starTours->AddReaction("Hold Tight");

    // Grand Avenue
    muppetVision->AddReaction("Laugh");
    muppetVision->AddReaction("Relax");

    // Galaxy's Edge (I don't know what the reactions are for either of these rides IRL since I've never gone on them and don't want to spoil it for myself so I'm just guessing)
    smugglersRun->AddReaction("Focus");
    smugglersRun->AddReaction("Amazement");
    smugglersRun->AddReaction("Wonder");
    smugglersRun->AddReaction("\"We're on the fkn Millenium Falcon\"");
    
    resistance->AddReaction("Amazement"); 
    resistance->AddReaction("Wonder");

    // Pandora (The World Of Avatar)
    flightOfPassage->AddReaction("Wonder");
    flightOfPassage->AddReaction("Hold Tight");
    flightOfPassage->AddReaction("Amazement");

    riverJourney->AddReaction("Wonder");
    riverJourney->AddReaction("Amazement");
    riverJourney->AddReaction("Awe");

    // Africa
    safaris->AddReaction("Take Pictures");

    // Asia
    everest->AddReaction("Hold Tight");
    everest->AddReaction("Raise Your Arms");
    everest->AddReaction("Scream");
    everest->AddReaction("Holy Shit");

    kaliRiverRapids->AddReaction("Scream");
    kaliRiverRapids->AddReaction("Laugh");
    kaliRiverRapids->AddReaction("Hold Tight");

    // Dinoland
    dinosaur->AddReaction("Scream");
    dinosaur->AddReaction("Hold Tight");
    dinosaur->AddReaction("Ragdoll");

    triceratopSpin->AddReaction("Whirl");
    triceratopSpin->AddReaction("Joy");

    primevalWhirl->AddReaction("Ragdoll");
    primevalWhirl->AddReaction("Hold Tight");
    primevalWhirl->AddReaction("Scream");
    primevalWhirl->AddReaction("Puke");

    #pragma endregion LOCATION/RIDE_SETUP

    string playerName;
    int yesNo;
    do {
        cout << "Please insert the character's name" << endl;
        cin >> playerName;
        
        if (cin.fail()) {
            cerr << "Sorry but that input is invalid" << endl;
            cin.clear();

            #undef max 

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        cout << endl << "Are you sure that you want " << playerName << " to be the character's name?" << endl;
        cout << "0. No" << endl;
        cout << "1. Yes" << endl;
        cout << endl << "Please insert a number from 0 to 1" << endl;
        
        do {
            cin >> yesNo;

            if (cin.fail()) {
                cerr << endl << "Sorry but that input is invalid, please insert a number from 0 to 1" << endl;
                cin.clear();

                #undef max 

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                yesNo = -1;

                continue;
            }
            else if (yesNo == 0) {
                cout << endl; 
                break;
            }
            else if (yesNo == 1) {
                break;
            }
            else {
                cerr << endl << "Sorry but that input is invalid, please insert a number from 0 to 1" << endl;
                cin.clear();

                #undef max 

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                yesNo = -1;

                continue;
            }
        } while (yesNo != 1);
    } while (yesNo != 1);

    Player* player = new Player(playerName);
    player->SetLocation(hub);
    
    int reactionVariable;
    int exitVariable;
    int playerInput;
    
    do {
        player->GetLocation()->DisplayLocation();

        reactionVariable = player->GetLocation()->NumberOfExits();
        exitVariable = reactionVariable + 1;

        cout << endl << "You can do the following actions:" << endl;
        cout << reactionVariable << ". Check Reactions" << endl;
        cout << exitVariable << ". Exit Game" << endl;
        cout << endl << "What would you like to do? (insert a number)" << endl;

        playerInput = NULL;
        do {
            cin >> playerInput;

            if (cin.fail()) {
                cerr << "Sorry but that input is invalid, please insert a number from 0 to " << exitVariable << endl;
                cin.clear();

                #undef max 

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                playerInput = NULL;

                continue;
            }
            else if (playerInput > exitVariable|| playerInput < 0) {
                cerr << "Please insert a number from 0 to " << exitVariable << endl;
                cin.clear();

                #undef max 

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                playerInput = NULL;

                continue;
            }
        } while (playerInput > exitVariable || playerInput < 0);

        if (playerInput < player->GetLocation()->NumberOfAreas()) {
            if (!player->GetLocation()->AreaName(playerInput)->IsTrain()) {
                player->SetLocation(player->GetLocation()->AreaName(playerInput));

                cout << endl << player->GetName() << " walks to " << player->GetLocation()->GetName() << endl;
            }
            else {
                railroad->DisplayCurrentLocation(player->GetLocation());

                cout << endl << "What would you like to do? (insert a number)" << endl;

                playerInput = NULL;
                do {
                    cin >> playerInput;

                    if (cin.fail()) {
                        cerr << "Sorry but that input is invalid, please insert a number from 0 to " << railroad->NumberOfExits() << endl;
                        cin.clear();

                        #undef max 

                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        playerInput = NULL;

                        continue;
                    }
                    else if (playerInput > railroad->NumberOfExits() || playerInput < 0) {
                        cerr << "Please insert a number from 0 to " << railroad->NumberOfExits() << endl;
                        cin.clear();

                        #undef max 

                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        playerInput = NULL;

                        continue;
                    }
                } while (playerInput > railroad->NumberOfExits() || playerInput < 0);

                railroad->DisplayDestination(railroad->AreaName(playerInput));
                player->SetLocation(railroad->AreaName(playerInput));

                cout << endl << player->GetName() << " exits at " << player->GetLocation()->GetName() << endl;
            }
        }
        else if (playerInput > player->GetLocation()->NumberOfAreas() -1 && playerInput <= player->GetLocation()->NumberOfExits() - 1) {
            player->GetLocation()->RideName(playerInput)->DisplayLocation();
            player->AddReactions(player->GetLocation()->RideName(playerInput)->GetReactions());
        }
        else if (playerInput == reactionVariable) {
            player->DisplayReactions();
        }
        else if (playerInput == exitVariable) {
            break;
        }
    } while (playerInput != exitVariable);

    #pragma region DELETE_ALL

    // Delete Hub
    delete hub;

    // Delete Magic Kingdom Locations
    delete magicKingdomEntrance;

    delete mainStreetUSA;
    delete emporium;
    
    delete railroad;

    delete castle;

    delete adventureland;
    delete jungleCruise;
    delete piratesOfTheCaribbean;
    delete tikiroom;
    delete carpets;

    delete frontierland;
    delete splashMountain;
    delete bigThunderMountain;

    delete libertySquare;
    delete hauntedMansion;

    delete fantasyland;
    delete smallWorld;
    delete peterPan;
    delete carrousel;
    delete mineTrain;
    delete underTheSea;
    delete madTeaParty;

    delete storybookCircus;
    delete dumbo;
    delete barnstormer;

    delete tomorrowland;
    delete spaceMountain;
    delete peopleMover;
    delete laughFloor;
    delete astroOrbiter;
    delete autopia;

    // Delete Epcot Locations
    delete epcotEntrance;

    delete futureWorld;
    delete spaceshipEarth;
    delete theSeas;
    delete theLand;
    delete soarin;
    delete figment;
    delete missionSpace;
    delete testTrack;
    
    delete worldShowcase;
    delete granFiestaTour;
    delete frozen;
    
    // Delete Hollywood Studios Locations
    delete hollywoodStudiosEntrance;
    delete hollywoodBoulevard;
    delete echoLake;
    delete pixarPlace;
    
    delete toyStoryLand;
    delete toyStoryMania;
    delete slinky;
    delete saucers;

    delete commissaryLane;
    delete starTours;
    
    delete grandAvenue;
    delete muppetVision;
    
    delete galaxysEdge;
    delete smugglersRun;
    delete resistance;
    
    delete animationCourtyard;
    delete runawayRailroad;
    
    delete sunsetBoulevard;
    delete towerOfTerror;
    delete rockNRollercoaster;

    // Delete Animal Kingdom Locations
    delete animalKingdomEntrance;
    delete oasis;
    delete discoveryIsland;
    
    delete pandora;
    delete flightOfPassage;
    delete riverJourney;
    
    delete africa;
    delete safaris;
    
    delete asia;
    delete everest;
    delete kaliRiverRapids;
    
    delete dinoland;
    delete dinosaur;
    delete triceratopSpin;
    delete primevalWhirl;

    // Delete Player
    delete player;

    #pragma endregion DELETE_ALL

    return 0;
}

/*
    Idea:   You are visiting Disney World, you can travel to each of the parks and each area found at the parks and are tasked with riding each ride and collect all of the reactions.

            Magic Kingdom:
                Main Street, USA (entrance):
                    Walt Disney Railroad (will allow you to fast travel between Storybook Circus, Main Street USA, and FrontierLand)
                        - Fast Travel
                Fantasyland:
                    Walt Disney Railroad
                        - Fast Travel
                    7 Dwarfs Mine Train
                        - raise your arms
                        - sing along
                    Under The Sea
                        - sing along
                        - amazement
                    Prince Charming Regal Carrousel
                        - Joy
                        - whirl
                    Mad Tea Party
                        - dizzy
                        - spin
                    Its a Small World
                        - Spooked "you find the dolls creepy"
                    Peter Pan's Flight
                        - wonder
                Storybook Circus
                    Goofy's Barnstormer
                        - raise your arms
                        - Joy
                    Dumbo the Flying Elephant
                        - whirl
                        - Joy
                Tomorrowland:
                    Space Mountain
                        - hold tight
                        - scream
                    The Peoplemover
                        - amazement
                        - wonder
                    Buzz Lightyear's Space Ranger Spin
                        - blast
                        - focus
                    Tomorrowland Speedway
                        - Awe
                        - Wonder
                        - relaxation
                    Monsters, Inc. Laugh Floor
                        - laughter
                        - relaxation
                    Astro Orbiter
                        - zoom
                        - whirl
                        - Joy
                Frontierland:
                    Walt Disney Railroad
                        - Fast Travel
                    Splash Mountain
                        - sing along
                        - raise your arms
                    Big Thunder Mountain
                        - ragdoll
                        - hold tight
                Adventureland:
                    Pirates Of The Carribean
                        - amazement
                        - wonder
                    Jungle Cruise
                        - laughter
                    The Magic Carpets of Aladin
                        - whirl
                        - Joy
                Liberty Square:
                    Haunted Mansion
                        - spooked
                    River Boats
                        - relaxation

            Animal Kingdom:
                Oasis (entrance)
                Discovery Island
                DinoLand USA
                    Dinosaur
                        - scream
                        - hold tight
                        - ragdoll
                    Primeval Whirl
                        - ragdoll
                        - hold tight
                    TriceraTop Spin
                        - wonder
                        - Joy
                Asia
                    Expedition Everest
                        - hold tight
                        - raise hands
                        - scream
                    Cali River Rapids
                        - scream
                        - laugh
                        - hold tight
                Africa
                    Kilimanjaro Safaris
                        - wonder
                        - take pictures
                Pandora (The World Of Avatar)
                    Flight Of Passage
                        - wonder
                        - hold tight
                    Na'vi River Journey
                        - wonder
                        - amazement

            EPCOT:
                Future World:
                    Spaceship Earth
                        - wonder
                        - amazement
                        - relaxation
                    The Seas With Nemo & Friends
                        - Joy
                        - wonder
                    Living With The Land
                        - relaxation
                    Soarin' Around The World
                        - wonder
                        - amazement
                        - scream
                        - Joy
                    Journey Into Imagination With Figment
                        - laughter
                        - sing along
                        - recoil (theres a part where you smell skunk)
                    Mission: SPACE
                        - dizzy
                        - hold tight
                        - amazement
                        - scream
                    Test Track
                        - wonder
                        - raise your arms
                        - hold tight
                World Showcase:
                    Gran Fiesta Tour Starring The Three Caballeros
                        - dance along
                    Frozen Ever After
                        - sing along
                        - dance along

            Hollywood Studios:
                Hollywood Boulevard
                Sunset Boulevard:
                    Tower Of Terror
                        - scream
                        - raise your arms
                        - hold tight
                    Rock N Rollercoaster
                        - scream
                        - hold tight
                        - holy shit
                Animation Courtyard
                    Mickey & Minnie's Runaway Railway
                        - relaxation
                        - wonder
                        - amazement
                Pixar Place
                    Toy Story Mania!
                        - blast
                        - focus
                Toy Story Land
                    Toy Story Mania!
                        - blast
                        - focus
                    Slinky Dog Dash
                        - raise your arms
                        - zoom
                        - wooo
                    Alien Swirling Saucers
                        - dizzy
                        - hold tight
                        - spin
                Star Wars Galaxy's Edge
                    Millennium Falcon: Smugglers Run
                        - focus
                        - amazement
                        - wonder
                        - "bro we're in the fkn Millenium Falcon"
                    Rise Of The Resistance
                        - amazement
                        - wonder
*/