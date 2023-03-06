Final project build for Chatbots course

The goal of this project was to build a fully-fledged chatbot, that would be able to provide a meaningful conversation when also being able to answer specific questions about Computer Science degree at the University of Wroclaw/

The main language of the bot is Polish.
Chatbot was built using huggingface with added layer of machine translation in order to use more sophisticated English language models with Polish as a language of choice. 
It features language detection section that allows to talk in English as well

Another important parts are: scraping module from University webpages and rule based part that work together with transformers and machine translation module.
Translation is provided in two version: with huggingface model and DeepL API (developer token needed).

Main file combines the code and also shows few examples of the usage

Project was developed using Google Colab in order to get access to GPU, that's why project is using .ipynb files.
