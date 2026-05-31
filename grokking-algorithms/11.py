#same way of the last exercise
cache = {}

def take_page(url):
    if cache.get(url): #se estiver, mostra dados cache
        return cache[url] 
    else: #faz o servidor trabalhar
        data = take_data_server(url)
        cache[url] = data
        return data