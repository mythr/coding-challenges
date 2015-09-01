#include <string>
#include <map>
#include <iostream>

std::map<std::string,std::string> nameGene;
std::map<std::string,std::string> firstChildParent;
std::map<std::string,std::string> secondChildParent;
std::string geneStatuses[3] = {"dominant","recessive","non-existent"};
int nMax = 3100;


std::string getChildGene(std::string& firstGene, std::string& secondGene){
	std::string childGene;
	if(firstGene == geneStatuses[0] && secondGene == geneStatuses[0])
		childGene = geneStatuses[0];
	else if(firstGene == geneStatuses[0] && secondGene == geneStatuses[1])
		childGene = geneStatuses[0];
	else if(firstGene == geneStatuses[1] && secondGene == geneStatuses[0])
		childGene = geneStatuses[0];
	else if(firstGene == geneStatuses[1] && secondGene == geneStatuses[1])
		childGene = geneStatuses[1];
	else if(firstGene == geneStatuses[2] && secondGene == geneStatuses[0])
		childGene = geneStatuses[1];
	else if(firstGene == geneStatuses[0] && secondGene == geneStatuses[2])
		childGene = geneStatuses[1];
	else if(firstGene == geneStatuses[2] && secondGene == geneStatuses[1])
		childGene = geneStatuses[2];
	else if(firstGene == geneStatuses[1] && secondGene == geneStatuses[2])
		childGene = geneStatuses[2];
	else if(firstGene == geneStatuses[2] && secondGene == geneStatuses[2])
		childGene = geneStatuses[2];

	return childGene;
}

std::pair<std::string,std::string> findParentGene(std::string child){
	std::string firstGene;
	std::string secondGene;
	std::string parent = firstChildParent.find(child) -> second;
	std::string otherParent = secondChildParent.find(child) -> second;
	std::map<std::string,std::string>::iterator it = nameGene.find(parent);
	if(it != nameGene.end())
		firstGene = it -> second;
	else
	{
		std::pair<std::string,std::string> parentGenes = findParentGene(parent);
		firstGene = getChildGene(parentGenes.first,parentGenes.second);
	}
	it = nameGene.find(otherParent);
	if(it != nameGene.end())
		secondGene = it-> second;
	else
	{
		std::pair<std::string,std::string> parentGenes = findParentGene(otherParent);
		secondGene = getChildGene(parentGenes.first,parentGenes.second);
	}

	return std::pair<std::string,std::string> (firstGene,secondGene);

}

int main(){
	int lines = 0;
	std::cin >> lines;
	for(int i = 0; i < lines; i++){
		std::string firstParent;
		std::string geneStatus;
		std::cin >> firstParent;
		std::cin >> geneStatus;
		if(geneStatus == geneStatuses[0] || geneStatus == geneStatuses[1] || geneStatus == geneStatuses[2]){
			nameGene.insert(std::pair<std::string,std::string>(firstParent,geneStatus));
		}
		else{
			std::pair<std::map<std::string,std::string>::iterator,bool> ret;
			ret = firstChildParent.insert(std::pair<std::string,std::string>(geneStatus,firstParent));
			if(ret.second == false){
				secondChildParent.insert(std::pair<std::string,std::string>(geneStatus,firstParent));
			}
		}

	}

	for(std::pair<std::string,std::string> p : firstChildParent){
		std::string child = p.first;
		std::pair<std::string,std::string> parentGenes = findParentGene(child);
		std::string firstGene = parentGenes.first;
		std::string secondGene = parentGenes.second;
		std::string childGene = getChildGene(firstGene,secondGene);
		nameGene.insert(std::pair<std::string,std::string>(child,childGene));

	}

	for(std::pair<std::string,std::string> p : nameGene){
		std::cout << p.first << " " << p.second << std::endl;
	}

	return 0;
}