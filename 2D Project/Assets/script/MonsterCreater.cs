using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterCreater : MonoBehaviour
{
    public GameObject obj = null;
    public float cycle = 0f;
    // Start is called before the first frame update
    void Start()
    {
        cycle += Random.Range(0f, 2f);
    }

    // Update is called once per frame
    void Update()
    {
        cycle += Time.deltaTime;
        if (cycle >= 3.5f)
        {
            cycle = Random.Range(0f, 2f);
            Instantiate(obj,new Vector3(10f,-3f,0f), Quaternion.identity);
        }

        if (obj.transform.position.x <= -12)
        {
            Destroy(obj, 0f);
        }//오브젝트가 전부 파괴되면 생성되지 않는데 어케해야될지 모르게서영
    }
}
