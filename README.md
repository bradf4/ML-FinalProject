<a href="https://dataturks.com/projects/abhishek.narayanan/Dataset%20for%20Detection%20of%20Cyber-Trolls?fbclid=IwAR1z4Mv4bEnX-vwZs9GWvJjoTLq1p0JDgLu5hwYU6xsPleWW0mx6yC6PEg0">This package includes the code we made to use prelabeled data which has 20,000 tweets classified either for being aggressive or not.</a>

Before we needed data to test the machine learning algorithm, we first used code from the University of Wisconsin - Madison, with data they gave to train the SVM. 
  - <a href="http://research.cs.wisc.edu/bullying/data.html ">BullyingtraceV2.zip has the code necessary to take in lines of text and predict if the text is bullying or not. They include a program enrichment.java that would remove examples that don't contain certain keywords, which we
decided to not use in order to compare the prediction to the already labeled data. We also used the bullyingV3.zip for the training data, in the data.csv.</a>

Using this we tried to see how correct the machine learning algorithm was to pre labeled data, however we acknowledge that the test data could
have been "poorly" labeled, and it's rather hard to obtain well labeled data without bias.

--------------------------------------------------------------------------------------
<b>Step 1: Setting up the Model</b>

The University of Wisconsin - Madison provided an open source pre-trained linear SVM model in which we used to detect whether a tweet or message contains cyber-bullying. To set this up for our test, we just made the java program using the provided makefile. After setting up, we were able to test our own data using a text file and the corresponding jar file. This model was trained using ~7000 tweets that the University labeled themselves.

--------------------------------------------------------------------------------------
<b>Step 2: Fitting the Test Data to the Model</b>

The data we used from dataturks came in the form of JSON file, with data unnecessary for the algorithm. We needed to strip the data in the form of a single tweet’s text on each line the data can be seen in data.txt. Running the parse.cpp will make two files with the tweet’s text (tweets.txt) and the labels of whether they contain aggression (labels.txt). We also had some repeated tweets in the data set and the total of tweets dropped to 19991.

--------------------------------------------------------------------------------------
<b>Step 3: Comparing the Prediction and Labels</b>

After successfully running our test data through the linear SVM model, we compared the output to the label that was given from dataturks. When comparing the results using comparing.cpp, we identified that the model provided by the University was able to correctly identify 11229 out of 19991 tweets, or accuracy of 56.17%.
