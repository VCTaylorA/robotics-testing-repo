# Goal for SCRB Gstreamer (from Felipe)
- we are using gstreamer to facilitate the interaction between the cameras themselves and paths to other things like encoding,,,
- encoding: we are using H.265 (software) as opposed to av1
- 


# Tutorials

documenting my learning process through Gstreamer

## Prerequisite knowldge
- comfortable with the basic workings of the c language and gcc
- get comfortable with navigating the linux terminal. useful commands like `cd`, `mkdir`,opening your editor
- understanding ROS2: debugging, publishers/subscribers etc.

## running and debug
you you can set your environment to log errors/bugs by doing 
`export GST_DEBUG="*:6"` to output everything
or
`GST_DEBUG=*:WARN`

## Tutorials
### basic-tutorial-1.c
what each line does:

