using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SubCamScript : MonoBehaviour
{
    GameObject subc;
    float h, v, y;
    [SerializeField]
    float speed = 5f;
    // Start is called before the first frame update
    void Start()
    {
        subc = GameObject.FindGameObjectWithTag("SubCamera");
    }

    private void FixedUpdate()
    {
        if(subc.GetComponent<Camera>().enabled == true)
        {
            move();
        }
    }

    // Update is called once per frame
    void Update()
    {
        h = Input.GetAxisRaw("Horizontal");
        v = Input.GetAxisRaw("Vertical");
        if (Input.GetKey(KeyCode.Space))
        {
            y = 1;
        }
        if (Input.GetKeyUp(KeyCode.Space)||Input.GetKeyUp(KeyCode.LeftShift))
        {
            y = 0;
        }
        if (Input.GetKey(KeyCode.LeftShift))
        {
            y = -1;
        }
    }

    void move()
    {
        Vector3 dir = new Vector3(h, v, -y);
        transform.Translate(dir.normalized * speed * Time.deltaTime);
    }
}
