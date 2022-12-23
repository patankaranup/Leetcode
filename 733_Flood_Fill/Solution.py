class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        current_color = image[sr][sc]
        height = len(image)
        width = len(image[0])

        def fill_color(r, c):
            if 0 <= r and r < height and 0 <= c and c < width and 
image[r][c] == current_color and image[r][c] != color:
                image[r][c] = color

                # call recursive method for top right bottom and left
                fill_color(r-1,c)
                fill_color(r,c+1)
                fill_color(r+1,c)
                fill_color(r,c-1)

        fill_color(sr,sc)

        return image


