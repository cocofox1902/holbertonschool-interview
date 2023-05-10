import requests


def count_words(subreddit, word_list, count={}):
    url = f'https://www.reddit.com/r/{subreddit}/hot.json?limit=100'
    headers = {'User-Agent': 'Mozilla/5.0'}
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()
    titles = [post['title'].lower() for post in data['data']['children']]

    for word in word_list:
        count[word] = count.get(word, 0) + titles.count(word.lower())

    if data['data']['after']:
        count_words(subreddit, word_list, count=count)
    else:
        sorted_count = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_count:
            print(f'{word}: {count}')
