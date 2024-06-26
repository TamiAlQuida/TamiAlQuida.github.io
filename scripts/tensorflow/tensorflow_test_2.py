import tensorflow as tf
import numpy as np
import cv2

# Load the pre-trained object detection model
model_dir = "scripts/tensorflow/ssd_mobilenet_v2_coco_2018_03_29"
model_path = model_dir + "/frozen_inference_graph.pb"

# Load the TensorFlow model into memory
detection_graph = tf.Graph()
with detection_graph.as_default():
    od_graph_def = tf.compat.v1.GraphDef()
    with tf.io.gfile.GFile(model_path, 'rb') as fid:
        serialized_graph = fid.read()
        od_graph_def.ParseFromString(serialized_graph)
        tf.import_graph_def(od_graph_def, name='')

# Initialize the webcam
cap = cv2.VideoCapture(0)

# Check if the webcam is opened correctly
if not cap.isOpened():
    print("Error: Could not open webcam.")
    exit()

# Create a named window
cv2.namedWindow('Webcam', cv2.WINDOW_NORMAL)

# Resize the window
cv2.resizeWindow('Webcam', 2560, 1440)  # Width, Height

def load_labels(path='/home/tomcarl/TamiAlQuida.github.io/models/research/object_detection/data/mscoco_label_map.pbtxt'):
    from object_detection.utils import label_map_util
    label_map = label_map_util.load_labelmap(path)
    categories = label_map_util.convert_label_map_to_categories(label_map, max_num_classes=90, use_display_name=True)
    category_index = label_map_util.create_category_index(categories)
    return category_index

category_index = load_labels()

# Perform object detection and display the results
with detection_graph.as_default():
    with tf.compat.v1.Session(graph=detection_graph) as sess:
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Error: Can't receive frame (stream end?). Exiting ...")
                break

            # Expand dimensions since the model expects images to have shape: [1, None, None, 3]
            image_np_expanded = np.expand_dims(frame, axis=0)

            # Extract image tensor
            image_tensor = detection_graph.get_tensor_by_name('image_tensor:0')
            # Extract detection boxes
            boxes = detection_graph.get_tensor_by_name('detection_boxes:0')
            # Extract detection scores
            scores = detection_graph.get_tensor_by_name('detection_scores:0')
            # Extract detection classes
            classes = detection_graph.get_tensor_by_name('detection_classes:0')
            # Extract number of detections
            num_detections = detection_graph.get_tensor_by_name('num_detections:0')

            # Actual detection
            (boxes, scores, classes, num_detections) = sess.run(
                [boxes, scores, classes, num_detections],
                feed_dict={image_tensor: image_np_expanded})

            # Visualization of the results of a detection.
            from object_detection.utils import visualization_utils as vis_util
            vis_util.visualize_boxes_and_labels_on_image_array(
                frame,
                np.squeeze(boxes),
                np.squeeze(classes).astype(np.int32),
                np.squeeze(scores),
                category_index,
                use_normalized_coordinates=True,
                line_thickness=8)

            # Display the resulting frame
            cv2.imshow('Webcam', frame)

            # Exit the loop when 'q' key is pressed
            if cv2.waitKey(1) == ord('q'):
                break

# When everything is done, release the capture and close the window
cap.release()
cv2.destroyAllWindows()
