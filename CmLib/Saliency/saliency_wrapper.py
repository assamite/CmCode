'''
.. py:module:: saliency_wrapper
    :platform: Unix

Wrapper for saliency.so
'''
from ctypes import cdll, c_char_p, c_bool
SaliencyDetector = cdll.LoadLibrary("./saliency.so")
SaliencyDetector.saliency.restype = c_bool

class SaliencyWrapper():
    '''Python wrapper for saliency detection written in C++.
    '''
     
    def saliency(self, image_path, saliency_map_path, saliency_mask_path):
        '''Detect saliency from the picture using ``saliency.so``.   
        
        :param image_path: Path to the image file
        :type image_path: str
        :param saliency_map_path: Path to save generated saliency mapping. 
        :type saliency_map_path: str
        :param saliency_mask_path: Path to save binarized saliency mapping. 
        :type saliency_mask_path: str
        :returns: bool --  True if saliency extraction was succesful, False otherwise.   
        '''       
        cimage_path = c_char_p(image_path)
        csaliency_map_path = c_char_p(saliency_map_path)
        csaliency_mask_path = c_char_p(saliency_mask_path)
        ret = SaliencyDetector.saliency(cimage_path, csaliency_map_path, csaliency_mask_path)
        return ret
        

if __name__ == "__main__":
    sw = SaliencyWrapper()
    print sw.saliency("/Users/pihatonttu/matlab/straw.jpg", "/Users/pihatonttu/matlab/straws.jpg", "/Users/pihatonttu/matlab/strawss.jpg")