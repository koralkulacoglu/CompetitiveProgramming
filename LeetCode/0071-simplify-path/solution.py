class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = path.split('/')
        newDirs = []
        for d in dirs:
            if not d or d.isspace():
                continue
            elif d == '.':
                continue
            elif d == '..':
                if len(newDirs):
                    newDirs.pop()
            else:
                newDirs.append(d)

        return '/' + '/'.join(newDirs)
