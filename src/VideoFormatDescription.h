



#ifndef TCAM_VIDEOFORMATDESCRIPTION_H
#define TCAM_VIDEOFORMATDESCRIPTION_H

#include "base_types.h"

#include "VideoFormat.h"

#include <vector>

namespace tcam
{


struct res_fps
{
    tcam_image_size resolution;
    std::vector<double> fps;
};


class VideoFormatDescription
{
public:

    VideoFormatDescription () = delete;

    VideoFormatDescription (const struct tcam_video_format_description&,
                            const std::vector<res_fps>&);

    VideoFormatDescription (const VideoFormatDescription&);


    VideoFormatDescription& operator= (const VideoFormatDescription&);

    bool operator== (const VideoFormatDescription& other) const;
    bool operator!= (const VideoFormatDescription& other) const;

    /**
     * Returns a struct representation of the format description
     * @return tcam_video_format_description
     */
    struct tcam_video_format_description getStruct () const;

    /**
     * Returns the pixel format used
     * @return uint32 containging the fourcc
     */
    uint32_t getFourcc () const;

    std::vector<res_fps> getResolutionsFramesrates () const;

    std::vector<tcam_image_size> getResolutions () const;

    tcam_image_size getSizeMin () const;
    tcam_image_size getSizeMax () const;

    std::vector<double> getFrameRates (const tcam_image_size& size) const;

    VideoFormat createVideoFormat (unsigned int width,
                                   unsigned int height,
                                   double framerate) const;

    bool isValidVideoFormat (const VideoFormat&) const;

    bool isValidFramerate (const double framerate) const;

    bool isValidResolution (unsigned int width, unsigned int height) const;

private:

    tcam_video_format_description format;

    std::vector<res_fps> rf;

};

} /* namespace tcam */

#endif /* TCAM_VIDEOFORMATDESCRIPTION_H */
