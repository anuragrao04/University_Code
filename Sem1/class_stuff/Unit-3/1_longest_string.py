def returnLongestLength(*strings):
    length = 0

    for string in strings:
        if len(string) > length:
            length = len(string)
        
    return length

print(returnLongestLength('hello', 'helloooo', 'hellooooooooooooooooooo', 'hell'))

