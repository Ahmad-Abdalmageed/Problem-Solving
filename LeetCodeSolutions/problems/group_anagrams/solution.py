class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams_hash = collections.defaultdict(list)

        # for every string in the list create count array
        for word in strs:
            anagrams_hash[tuple(sorted(word))].append(word)
        return anagrams_hash.values()