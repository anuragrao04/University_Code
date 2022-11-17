
# 1)Consider the following text for the problems below.

# str_places = '''karnataka bangalore lalbagh
# tamilnadu kanyakumari vivekananda_rock
# kerala thiruvananthapuram padmanabha_temple
# kerala idukki munnar
# karnataka mysore brindavan_gardens
# karnataka mysore mysore_palace
# karnataka hassan shravanabelagola
# tamilnadu chennai egmore_museum
# tamilnadu kanyakumari kaamaakshmi_temple
# karnataka bangalore cubbon_park
# karnataka hampi maharnavami_dibba'''


#  1. Find and print the number of states and their names (unique).
#  2. Find and print the number of cities and their names for each state and find the number of cities for each state.
#  3. Find and print the number of places and their names for state-city combination.
#  4. find the number of places for state-city combination 


str_places = '''karnataka bangalore lalbagh
tamilnadu kanyakumari vivekananda_rock
kerala thiruvananthapuram padmanabha_temple
kerala idukki munnar
karnataka mysore brindavan_gardens
karnataka mysore mysore_palace
karnataka hassan shravanabelagola
tamilnadu chennai egmore_museum
tamilnadu kanyakumari kaamaakshmi_temple
karnataka bangalore cubbon_park
karnataka hampi maharnavami_dibba'''

l = list(map(str.split, str_places.split('\n')))


stateCities = {} # DS = state:{set of cities}
stateCityPlace = {} # DS = str(state city) : {set of places}

for i in l: 
    if i[0] not in stateCities:
        stateCities[i[0]] = {i[1]}
    else:
        stateCities[i[0]].add(i[1])


    if i[0]+' '+i[1] not in stateCityPlace:
        stateCityPlace[i[0]+' '+i[1]] = {i[2]}
    else:
        stateCityPlace[i[0]+' '+i[1]].add(i[2])
   
    
#1
states = list(stateCities.keys())
print(f"{len(states)} states: \n{states}\n\n")

#2
for i in stateCities:
    cities = stateCities[i]
    print(f"State: {i} \n{len(cities)} Cities: {cities}")
print('\n')

#3 and #4
for i in stateCityPlace:
    places = stateCityPlace[i]
    print(f"{i} \n{len(places)} {'place' if len(places) == 1 else 'places'}: {places} ")


 





