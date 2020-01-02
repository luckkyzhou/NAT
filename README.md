# NAT
## Program
1. Test my solution
- Predefine a NAT.txt and FLOW.txt.
- Call the main method.
- Show output on windows console.
2. Interesting design
- Use a map to store nat rules.
- During match flow with nat rules, I complete that with three steps. First, match those are absolutely equaled. Second, use "\*" to replace ip in flow and match again. Thirdly, use "\*" to replace port in flow and match. Finally, if we can't match anything, print "No nat match for ip:port".
3. Optimization
- The first thing is to use object-oriented principles to encapsulate program methods.
- Add methods to judge whether input flows are valid ip and port format.
- When datasets become large, we could gather those have same ip and same port in flow files. And then we could handle those data together.
- Call those have "\*" either in ip or in port in nat rules. Match these data first, the program can be faster.
4. More well define the challenge
- Predefine a NAT.txt and FLOW.txt to store inputs.
5. Something else to highlight
- This project is based on c++. Use NAT.cpp to run this program.

## Functionality
1. Yes, the code work correctly
- The INPUT is NAT.txt and FLOW.txt.
- The OUTPUT is below.
![](/output.png "output")
2. Yes, the program will throw error if txt files can't be opened.
- But the program could be optimized by adding error throw at checking whether input flows are valid.

## Code clarity and cleanliness
1. The code is well structured. But I don't use object-oriented principles.
- I will optimize the program later with object-oriented principles at how to encapsulate the whole program.
2. The logic is not well encapsulated.
- Same as above, I will encapsulate the whole program later.
3. Yes, it is easy to understand the code. The names of variables and functions are descripted with comments. And the code is simple, avoiding overly complex.

## Performance
1. The time complexity is O(n). n is the number of flow numbers. The space complexity is O(n). The program needs space to store nat entries and flow entries.
- I use a map to store nat transformation rules.
2. Optimization
- The first thing is to use object-oriented principles to encapsulate program methods.
- Add methods to judge whether input flows are valid ip and port format.
- When datasets become large, we could gather those have same ip and same port in flow files. And then we could handle those data together.
- Call those have "\*" either in ip or in port in nat rules. Match these data first, the program can be faster.
