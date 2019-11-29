using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraScript : MonoBehaviour
{
    [SerializeField]
    float speed = 5f;
    [SerializeField]
    float rspeed = 100f;
<<<<<<< HEAD
    [SerializeField]
    float jumpPower = 5f;
=======
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748

    GameObject cam;
    GameObject subC;

<<<<<<< HEAD
=======
    Rigidbody rigid;

    bool Q;
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
    float rx;
    float ry;
    float h;
    float v;
<<<<<<< HEAD

    Rigidbody rigid;
=======
    float wheel;
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748

    // Start is called before the first frame update
    void Start()
    {
<<<<<<< HEAD
        rigid = GetComponent<Rigidbody>();
        cam = GameObject.FindGameObjectWithTag("MainCamera");
        subC = GameObject.FindGameObjectWithTag("SubCamera");
        Cursor.lockState = CursorLockMode.Locked;
        rx = 0;
        ry = 0;
=======
        cam = GameObject.FindGameObjectWithTag("MainCamera");
        subC = GameObject.FindGameObjectWithTag("SubCamera");
        cam.transform.position = transform.position + Vector3.up * 1;
        rx = 0;
        ry = 0;
        wheel = 0;
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
    }

    private void FixedUpdate()
    {
<<<<<<< HEAD
        if (cam.GetComponent<Camera>().enabled == true)
        {
            move(h, v);
            rotate();
=======
        if (cam.GetComponent<Camera>().enabled)
        {
            if (Input.GetMouseButton(1))
            {
                rotate();
            }
            if (Input.GetMouseButton(2)||(Q&&Input.GetMouseButton(0)))
            {
                move(-h,-v);
            }
            move(wheel);
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
        }
    }

    // Update is called once per frame
    void Update()
    {
<<<<<<< HEAD
        h = Input.GetAxisRaw("Horizontal");
        v = Input.GetAxisRaw("Vertical");

        rx += Input.GetAxis("Mouse X") * rspeed * Time.deltaTime ;
        ry += Input.GetAxis("Mouse Y") * rspeed * Time.deltaTime ;
        
    }

    private void move(float h, float v)
    {
        Vector3 dir = new Vector3(h, 0, v);      
        transform.Translate(dir.normalized * speed * Time.deltaTime);
        cam.transform.position = transform.position + Vector3.up * 1;
=======
        if (Input.GetKeyDown(KeyCode.Q))
        {
            Q = !Q;
        }
        h = Input.GetAxisRaw("Mouse X");
        v = Input.GetAxisRaw("Mouse Y");

        if (Input.GetMouseButton(1))
        {
            rx += Input.GetAxis("Mouse X") * rspeed * Time.deltaTime;
            ry = Mathf.Clamp(ry, -90, 90);
            ry += Input.GetAxis("Mouse Y") * rspeed * Time.deltaTime;            
        }

        wheel = Input.GetAxis("Mouse ScrollWheel");
    }
        
    private void move(float h, float v)
    {
        Vector3 dir = new Vector3(h, v, 0);      
        transform.Translate(dir.normalized * speed * Time.deltaTime);

>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
        subC.transform.position = transform.position + Vector3.up * 15;
    }

    private void rotate()
<<<<<<< HEAD
    {    
        cam.transform.rotation = Quaternion.Euler(-ry, rx, 0);
        transform.rotation = Quaternion.Euler(0, rx, 0);
    }

    private void OnCollisionStay(Collision collision)
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            rigid.AddForce(Vector3.up * jumpPower, ForceMode.Impulse);
        }
=======
    {            
        transform.rotation = Quaternion.Euler(-ry, rx, 0);
    }

    private void move(float wheel)
    {
        Vector3 dir = new Vector3(0, 0, wheel) * speed * 30 * Time.deltaTime;
        transform.Translate(dir);
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
    }
}
