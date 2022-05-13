# Eternal-Sunshine
CS1021 Lab 10

## Introduction
After my birthday, my favorite day of the year is December 21st. My least favorite day of the year is June 21st. We'll come back to the (very good) reason for these choices later!

Thanks to Nicolaus Copernicus, [heliocentrism](https://en.wikipedia.org/wiki/Heliocentrism) is firmly established. Copernicus showed convincingly that the Earth revolves around the sun, not the other way around. Proven in the 1500s by using astronomical observation and mathematical models, the idea that the sun is fixed and we are in its orbit had tremendous philosophical and scientific consequences. Copernicus' "discovery" has been coined the [Copernican Revolution](https://www.britannica.com/topic/Copernican-Revolution).

During a single rotation around the sun, we humans spend 365 days working, laughing, and living -- a full year! In that span, the earth rotates on its vertical axis 365 times. Each rotation about the vertical axis is a single day. A Washington Post [article](https://www.washingtonpost.com/lifestyle/kidspost/ever-wondered-why-days-get-shorter-in-winter/2018/12/10/2fae8b0e-fa35-11e8-8d64-4e79db33382f_story.html) describes the motion of the Earth around the Sun and about its vertical axis like this:

> Imagine a basketball player twirling the Earth on her finger while also running in a circle around a spot on the floor. That spot is the sun, and our planet is the doubly twirling basketball! Each twirl on the player’s finger makes up one day, while each circle she completes on the floor is a year.

The part of the basketball facing away from the sun gets no light, obviously. Continuing the metaphor, the part of the ball getting no light is having its night. The opposite is true for the part of the Wilson bathed in sun: it is having its day.

If this metaphor held up in reality, every place on earth would experience days that were always roughly the same length as nights. Unfortunately, unlike the basketball spinning on our cager's finger, Earth's vertical axis is not perfectly straight up and down. Earth tilts at an angle of approximately 23 degrees.

As the Earth rotates around the sun, this skew affects the seasons: When the Northern Hemisphere is close to the sun, it is having Summer and the Southern Hemisphere is having Winter; when the Southern Hemisphere is close to the sun, it is having Summer and the Northern Hemisphere is having Winter. Besides affecting the way that different places on Earth experience the seasons, the tilt affects the amount of time that various places on Earth are in daylight. Check out this informational video (https://www.youtube.com/watch?v=Em3TlqNOUsk) if you want to see a nice illustration of what I just attempted to describe in clunky English.

In Cincinnati, between June and December, each day is shorter than the last; between December and June, each day is longer than the last!

And now you know why December 21st is my favorite day of the year: it marks the annual point when we transition from having gradually shortening days to gradually lengthening days. And June 21st is bittersweet: it's both the longest day of the year (when I can stay outside playing in the sun the longest) and it is the day when we cross the rubicon from lengthening days to shortening days.

In this lab, you are going to write a program, SolarFlare, that uses an Internet service to compare the difference in the amount of daylight for two given days. The program will get its data from a service named [Sunrise Sunset](https://sunrise-sunset.org/) that catalogs sunrises and sunsets around the world. Your program will query for the amount of daylight on a particular day using Sunrise Sunset's application programming interface (API). There are many different types of APIs, but Sunrise Sunset's [Web API](https://en.wikipedia.org/wiki/Web_API) is an API that runs over the [HTTP protocol](https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol). A Web API is a protocol that governs how machines communicate with one another to transfer data, invoke remote computation, etc

The request takes a path from someone's computer to the Sunrise Sunset Web API and back again. First, That person's request is transmitted to the Web API over the Internet. Once his/her request reaches the Web API, a response is generated and returned to him/her. If you want to see what these requests and responses look like in real life, copy/paste

```
https://api.sunrise-sunset.org/json?lat=39.1031&lng=-84.5120&date=1982-02-09
```

in the `URL` field on the [https://www.httpdebugger.com/Tools/ViewHttpHeaders.aspx](https://www.httpdebugger.com/Tools/ViewHttpHeaders.aspx) website. Pretty cool to think that your lab code will get to work with such sophisticated technology!

*SolarFlare* will read two dates from a file, query the Sunrise Sunset API to determine the amount of daylight for those days (for Cincinnatians), calculate the difference between those two values and output an appropriate message.

The file containing the two dates will always be named `query_file.txt`. In a properly-formatted file, there will be two lines. On each line will be a date in YYYY-MM-DD, YYYY-MM-D, YYYY-M-DD, or YYYY-M-D format. If the input file is not properly formatted, *SolarFlare* will print an error message and exit.

*SolarFlare* will take the user's input and build and issue a request to the Sunrise Sunset Web API to download information about the sunrise/set/day-length of the given dates. (All interaction with the Web API can be accomplished using functions that will be provided to you -- you will simply have to invoke them properly). One item of data that the API provides is the length of the day, in seconds. *SolarFlare* will use that value and calculate the difference in daylight between the two given days.

Finally, *SolarFlare* will print out an appropriate message and that difference formatted as hours, minutes and seconds. *SolarFlare*'s output will look something like this:

```
2021-6-8 was 4 hour(s), 37 minute(s) and 11 second(s) longer than 2021-11-9.
```

when `query_file.txt` contained

```
2021-11-9
2021-6-8
```

Remember: [It's always darkest just before dawn](https://www.youtube.com/watch?v=UnLyypuGG6o).

Good luck!

## Program Design Task
As my dad always said, “Everyone will have their day in the spotlight.” Before you start writing code, please write the pseudocode or draw a flow chart for your implementation of the *SolarFlare* length-of-day-difference calculator.

## Program Design Requirements
Your pseudocode (or flow chart) must describe the entirety of the process you plan to use to

1. Read the user's input from the query_file.txt,
2. Alert the user if the input is malformed,
3. Instantiate the objects used to make the necessary Sunrise Sunset Web API calls,
4. Access the Sunrise Sunset Web API using the given functions,
5. Calculate the difference of day-length between the two days,
6. Convert that difference from seconds to hours, minutes and seconds, and
7. Display the results of the calculation to the user.

As usual, the *code you write must align with your pseudocode*.

## Programming Task and Requirements
Your programming task is to implement the *SolarFlare* application. If you are a Windows-based C++ developer, start with the skeleton .zip in this repository. You must use this skeleton to successfully complete this lab.

All user input will be taken from a file named `query_file.txt` which will be located in the same directory as the executing application. A properly-formatted `query_file.txt` will contain two dates on two separate lines. The dates may be formatted in a number of ways:

- YYYY-MM-DD
- YYYY-MM-D
- YYYY-M-DD
- YYYY-M-D

all of which are valid. *SolarFlare* must work correctly when given inputs in any of those formats. If *SolarFlare* is given a file whose contents do not match that format, it will output

```
Oops: Could not read two valid dates from file.
```

## Programming: The Infrastructure
You have been given two functions that will enable you to download and extract the important bits of information from the Sunrise Sunset Web API. In order to interact with those functions, you must pass a reference to a C++ `class` whose name is `LocationDateLength`. The `LocationDateLength` class represents, conceptually, the length (in seconds) of a day at a given geographic location. In other words, a `LocationDateLength` can conceptually store the sentence, "On February 9th, 1982 the sun was up for 10 hours, 34 minutes and 10 seconds in Cincinnati, Ohio."

In order to represent this conceptual entity in code, the `LocationDateLength` `class` contains three private member variables:

1. An instance of a C++ `class` named `Date`.
2. An instance of a C++ `class` named `Location`.
3. A variable of type int that represents the length of the day identified by the member variable with type Date at the location identified by the member variable of type `Location`.

The `LocationDateLength` class must contain the following getters and setters:

- `getDate`: Return the date as a `Date`.
- `getLocation`: Return the location as a `Location`.
- `getLength`: Return the length of the day in seconds as an `int`.
- `setLength`: Take an `int` as a parameter and set its value as the `LocationDateLength`'s new length of day.

All getters must be declared as so-called const member functions. The `LocationDateLength` class must contain a default constructor. The `LocationDateLength` class must also contain a non-default constructor to initialize it from a date and a location. The first parameter to the `LocationDateLength` constructor must be an instance of a `Date` class. The second parameter to the non-default `LocationDateLength` constructor must be an instance of a `Location` class. See below for the description of the `Date` and `Location` user-defined types.

Your code must define what it means to take the difference between two `LocationDateLength`s. When the user subtracts two instances of the `LocationDateLength` class, the result will be the difference between the length of their days. In other words, if there are two instances of the `LocationDateLength` class (named `daylength_b` and `daylength_a`) after

```cpp
int daylength_difference = daylength_b - daylength_a;
```

executes, `daylength_difference` will contain the difference (in seconds) between the length of the day on/at date/location combination specified by `daylength_b` and the length of the day on/at the day/length combination specified by `daylength_a`. All implementation for the `LocationDateLength` class should be included in the `LocationDateLength.cpp` file. All definitions should be included in the `LocationDateLength.h` file.

The type of the member variable representing the date in the `LocationDateLength` is itself user defined. Your `Date` C++ class contains three private members variables, all of which are ints: one representing the day, one representing the month and one representing the year. The `Date` class must contain the following accessors and mutators:

- `getDay`: Returns the `Date`'s day, as an `int`.
- `getMonth`: Returns the `Date`'s month, as an `int`.
- `getYear`: Returns the `Date`'s year, as an `int`.
- `setDay`: Takes a day as a parameter (as an `int` type) and sets the `Date`'s day appropriately.
- `setMonth`: Takes a month as a parameter (as an `int` type) and sets the `Date`'s month appropriately.
- `setYear`: Takes a year as a parameter (as an `int` type) and sets the `Date`'s year appropriately.

All getters must be declared as `const` member functions. The Date class does not need anything more than a default constructor, however you may define additional constructors if they make your code cleaner.

A `Date` class should know how to print itself to the screen! In other words, you must overload the `<<` operator for the `Date` C++ class. In order to make the overloaded stream insertion operation useful for you when you put these pieces together to construct the final *SolarFlare* application, the format of a `Date` printed with the `<<` operator should be

```
YY(YY)-(M)M-(D)D
```

*SolarFlare* will format the year in the same way that it was stored in the query file. The month and the day field will be two digits *only if they are greater than or equal to ten* -- they will be a single digit otherwise. Therefore, April would be printed as `4` and not `04`. See below for additional examples of proper formatting.

All implementation for the `Date` class should be included in the `Date.cpp` file. All definitions should be included in the `Date.h` file.

Finally, the type of the member variable representing the location (`Location`) in the `LocationDateLength` user-defined type is, itself, user defined. It consists of two private member variables of type double that store the longitude and latitude. The `Location` class must contain the following accessors and mutators:

- `getLatitude`: Returns the `Location`'s latitude as a `double`.
- `getLongitude`: Returns the `Location`'s month, as a `double`.
- `setLatitude`: Takes a latitude as a parameter (as a `double` type) and sets the `Location`'s latitude appropriately.
- `setLongitude`: Takes a longitude as a parameter (as a `double` type) and sets the `Location`'s longitude appropriately.

Again, all getters must be `const` member functions. Although you must have a default constructor, there is no requirement that you write a non-default constructor. If you believe that it will make your code look nicer, then please do declare/define an additional constructor and use it appropriately!

All implementation for the `Location` class should be included in the `Location.cpp` file. All definitions should be included in the `Location.h` file.

## Programming: The Application Logic
Now that you have built the necessary infrastructure, you can turn to writing *SolarFlare*'s *application logic*. To make that easier, the skeleton provides several useful functions: `download`, `build_url_path` and `parse_json_daylength_response`. The following table defines their semantics.

| Name	| Parameters |	Return Value |	Semantics |
| --- | --- | --- | --- |
| `download` | 1. (in) The name of the server, a `std::string`, from which to download. You should always call this with the value `https://api.sunrise-sunset.org`. <br> 2. (in) The path, a `std::string`, of the Web API. Use the result of the `build_url_path` function (see below) to generate a valid argument for this parameter. <br> 3. (out) The content, a `std::string`, of the Web API's response. Use this as the argument for the first parameter of the `parse_json_daylength_response` function. | A `bool`; `true` if the Web API was successfully invoked and `false` otherwise.	| This function will use HTTPS to connect to the server, issue the Web API call and download the server's response. In the case of an error, the function will return `false`. Otherwise, the function will return `true`. |
| `build_url_path`	| 1. (in) The date and location, as a reference to a `LocationDateLength` class, for which to request the daylength from the Sunrise Sunset Web API. | A `std::string` that contains the properly-formatted path of the Sunrise Sunset Web API request for the given date and location. This string is suitable for passing to the download function (see above).	| The function will use the given `LocationDateLength` C++ class to generate parameters for a properly-formatted Web API query for the Sunrise Sunset API. The instance of the `LocationDateLength` class given as a parameter must contain valid values for the date and the location. The resulting `std::string` can be used as an argument to the download function.
| `parse_json_daylength_response`	| 1. (in) The resulting data, as a `std::string`, of the Sunrise Sunset Web API call. <br> 2. (out) A reference to a `LocationDateLength` class that is updated with the response from the Web API call (i.e., the first parameter). | A `bool`: `true` if the content downloaded from the Sunrise Sunset API was properly formatted; `false` otherwise. |	The data that the Sunrise Sunset Web API returns is formatted as JSON. This function will parse that data, extract the daylength, and invoke the proper setters on the instance of the `LocationDateLength` passed by reference as the second parameter. |

If any of those functions fails, *SolarFlare* must output:

```
Oops: There was a Web API error. 
```

Using the results from the functions defined above, *SolarFlare* will calculate the differences between the length of the days that the user specified. *SolarFlare* will display that difference in the equivalent number of hours, minutes and seconds.

Look back at the pseudocode that you wrote to help you design the overall structure of your *SolarFlare* implementation. Thanks to the user-defined types that we built and the three provided functions, it is possible to be more explicit about the way *SolarFlare* should operate.

```
main()
    Attempt to open query_file.txt; print an appropriate error message and exit if there is a failure.
    Attempt to read two dates (DA and DB) from query_file.txt; print an appropriate error message and exit if there is a failure.
    Create two instances of the user-defined Date type (DateA, DateB) from DA and DB.
    Create two instances of the user-defined Location type (LocationA, LocationB) that match Cincinnati's place on the map.
    Create two instances of the user-define LocationDateLength type (LDLA, LDLB) from LocationA/B and DateA/B.
    Build two URL paths (build_url_path) (URLPathA, URLPathB) from the A/B date and location; print an appropriate error message and exit if there is a failure.
    Download the day-length information from the Sunrise Sunset Web API (download) using URLPathA and URLPathB (store as ResultA, ResultB); print an appropriate error message and exit if there is a failure.
    Extract the day lengths from ResultA and ResultB and store them in LDLA/LDLB using the parse_json_daylength_response function; print an appropriate error message and exit if there is a failure.
    Using your implementation of the overloaded operator- for the user-defined LocationDateLength type to determine the difference in the number of seconds of daylight between the two days.
    Convert that result from seconds to hours, minutes and seconds.
    Print the proper output to the console.
```

Once you have a perfect implementation of *SolarFlare*, for an invocation of it with

```
2021-11-9
2021-11-10
```

in `query_file.txt`, the output will be

```
2021-11-10 was 0 hour(s), 2 minute(s) and 1 second(s) shorter than 2021-11-9. 
```

For an invocation of *SolarFlare* with

```
2021-11-10
2021-6-9
```

in `query_file.txt`, the output will be

```
2021-6-9 was 4 hour(s), 39 minute(s) and 53 second(s) longer than 2021-11-10.
```
In other words, the general format of the output is

```
<date in the second line> was <X> hour(s), <Y> minute(s) and <Z> second(s) [longer|shorter] than <date in first line>.
```

*SolarFlare* will output months and days without leading zeros. In other words, April is `4` and not `04` and the first of the month is `1`, not `01`. *SolarFlare* will output years in exactly the way that they appear in `query_file.txt`.

*SolarFlare*'s calculation will always display the date on the second line of a properly-formatted query_file.txt file first. The difference will be calculated from the perspective of the date appearing on the second line of the query_file.txt file. In other words, for an invocation of *SolarFlare* with

```
2021-06-9
2021-1-10 
```

in `query_file.txt`, the output will be

```
2021-1-10 was 5 hour(s), 13 minute(s) and 42 second(s) shorter than 2021-6-9. 
```

Although you are not required to write any particular function to complete this lab, you are required to write modular code. In other words, you will write functions as you implement the *SolarFlare* application. Any function (yes, that includes member functions!) that you write must contain comments formatted according to the following specification:

```cpp
/*
 * <function name>
 *
 * <short description of what the function does>
 *
 * input: <short description of all input parameters>
 * output: <short description of all output parameters
 *          and the return value>
 */
 ```
 
For the implementation of *SolarFlare*, you may make the following assumptions:

1. The dates in the `query_file.txt` will always be in the past -- in other words, the Sunrise Sunset Web API will have data about their lengths of day.
2. *SolarFlare* users are always in [Cincinnati](https://www.latlong.net/place/cincinnati-oh-usa-6855.html) and always care about the length of the day in the Queen City.
3. The `query_file.txt` will be located in the same directory as the executing application.

For all values that do not change from execution to execution of *SolarFlare* (e.g., the longitude and latitude of Cincinnati, the name of the input file, the server name for the Sunrise Sunset Web API, etc), you must use globally named constants. Failure to do so will result in loss of points.

The main application logic of your *SolarFlare* application should go in the `SolarFlare.cpp` file.

## Critical Thinking Task
In myriad ways, people living in one country can affect people in another country, often in a very direct way. I can easily take out my iPhone and chat with a person living in South Korea. I can ship a package from here to Australia. Academic research from people in China spur innovation in the United States. Globalization is amazing. 

These connections, however, do not happen by accident. The ability for two people to communicate requires an agreement on the format of messages. The ability to transfer physical goods from Point A to Point B requires shared understanding about packages' size, shape and weight. The proliferation of academic knowledge requires a shared language and methodology.

These agreements are usually defined by national and international organizations formed by governments or private businesses. The standards' bodies are incredibly important in the field of computer science and telecommunications. For instance, the W3C specifies the valid syntax for a web page; the ISO C++ committee defines the syntax and semantics of the C++ programming language; and ANSI specifies the ASCII codes for a limited subset of characters that can be represented in a computer.

[Originally known as the European Computer Manufacturers Association, Ecma International - European association for standardizing information and communication systems](https://www.ecma-international.org/about-ecma/history/) is an international standards organization that is ["dedicated to the standardization of information and communication systems."](https://www.ecma-international.org/) [What is now called Ecma International was founded in 1960 and included the three major European computer manufacturers at the time: Compagnie des Machines Bull, IBM World Trade Europe Corporation and International Computers and Tabulators Limited.](https://www.ecma-international.org/about-ecma/history/) Ecma was an early proponent of Near-Field Communication protocols -- the technology that makes it possible to pay by tapping your credit card -- and established an early standard for it in [2003](https://en.wikipedia.org/wiki/Near-field_communication). [They are also actively involved in standardizing the formats that make it possible to share documents between Microsoft Office programs and other productivity tools](https://www.ecma-international.org/technical-committees/tc45/). Ecma is arguably most active in standardizing the syntax and semantics of programming languages. Committees at Ecma are responsible for standardizing [Dart](https://www.ecma-international.org/technical-committees/tc52/), [C#](https://www.ecma-international.org/task-groups/tc49-tg2/) and, most famously, [JavaScript](https://tc39.es/).

Your critical thinking task is to identify an organization that standardizes and promotes agreements used in computer science and telecommunications and describe their work.

## Critical Thinking Requirement
In 500 words or less, identify an organization that standardizes and promotes agreements used in computer science and telecommunications and describe their work. All references to external resources must be properly documented and formatted. The choice of formatting for external references is up to you, but you may find it helpful to consult the Purdue OWL for [information](https://owl.purdue.edu/owl/research_and_citation/apa_style/apa_style_introduction.html). The Purdue OWL also has extensive information on ways to [avoid plagiarism](https://owl.purdue.edu/owl/avoiding_plagiarism/index.html).

## Deliverables
1. The pseudocode describing the algorithms you used to implement the *SolarFlare* application in PDF format (named `design.pdf`).
2. The C++ source code for the *SolarFlare* application (named `SolarFlare.cpp, Location.cpp/h, LocationDateLength.cpp/h, Date.cpp/h`).
3. The response to the Critical Thinking prompts in PDF format (named `protocol.pdf`)

## Related Learning Objectives
1. Declaring, defining and using user-defined types.
2. Declaring, defining and using default and non-default constructors.
3. Declaring, defining and using overloaded operators.
4. Declaring, defining and using user-defined types whose members themselves are user-defined types.
