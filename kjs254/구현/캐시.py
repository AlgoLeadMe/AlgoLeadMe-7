def solution(cacheSize, cities):
    answer = 0
    cities = [city.lower() for city in cities]
    cache, cache_hit = [], []
    
    for i,city in enumerate(cities):
        if len(cache)<cacheSize and city not in cache:
            cache.append(city)
            cache_hit.append(i)
            answer +=5
            
        elif city in cache:
            cache_hit[cache.index(city)] =i
            answer +=1
            
        elif cache:
            idx = cache_hit.index(min(cache_hit))
            cache[idx] = city
            cache_hit[idx] = i
            answer +=5
            
        else:
            answer+=5

    return answer